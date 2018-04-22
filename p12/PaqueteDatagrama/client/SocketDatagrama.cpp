#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include <iostream>
#include <cstdlib>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h> // inet_ntoa()
#include <netinet/in.h> // ntohs()
#include <netdb.h>
#include <unistd.h> 
#include <sys/time.h>
#include <errno.h>

using namespace std;

SocketDatagrama::SocketDatagrama(int pto){
	s=socket(AF_INET,SOCK_DGRAM,0);
	bzero((char *)&direccionLocal, sizeof(direccionLocal));
	direccionLocal.sin_family=AF_INET;
	direccionLocal.sin_addr.s_addr=htonl(INADDR_ANY);
	direccionLocal.sin_port=htons(pto);
	bind(s, (struct sockaddr *) &direccionLocal, sizeof(direccionLocal));
}


int SocketDatagrama::recibe(PaqueteDatagrama &p){
	int clien = sizeof(direccionForanea);
	bzero((char *)&direccionForanea, sizeof(direccionForanea));
	int n= recvfrom(s, p.obtieneDatos() , p.obtieneLongitud(), 0, (struct sockaddr *) &direccionForanea, (socklen_t*) &clien);
	char* port=inet_ntoa(direccionForanea.sin_addr);
	p.inicializaIp(port);
	p.inicializaPuerto(ntohs(direccionForanea.sin_port));
	return n;
}

int SocketDatagrama::envia(PaqueteDatagrama &p){
	int clien = sizeof(direccionForanea);
	bzero((char *)&direccionForanea, sizeof(direccionForanea));
	direccionForanea.sin_family = AF_INET;
	direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
	direccionForanea.sin_port = htons(p.obtienePuerto());
	int n = sendto(s, p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *) &direccionForanea, clien);
	return n;
}

SocketDatagrama::~SocketDatagrama(){
	close(s);
}

void SocketDatagrama::setTimeout(time_t segundos, suseconds_t microsegundos)
{
	tiempo.tv_sec = segundos;
	tiempo.tv_usec = microsegundos;
	setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *)&tiempo, sizeof(tiempo));
	timeout = 1;	
}
void SocketDatagrama::unsetTimeout()
{
	tiempo.tv_sec = 0;
	tiempo.tv_usec = 000000;
	setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *)&tiempo, sizeof(tiempo));
  	timeout = 0;
}

int SocketDatagrama::recibeTimeout(PaqueteDatagrama & p)
{
	struct timeval tiempo2, res;
	int clien = sizeof(direccionForanea);
	bzero((char *)&direccionForanea, sizeof(direccionForanea));
	gettimeofday(&tiempo, NULL);
	int n= recvfrom(s, p.obtieneDatos() , p.obtieneLongitud(), 0, (struct sockaddr *) &direccionForanea, (socklen_t*) &clien);	
	gettimeofday(&tiempo2, NULL);
	timersub(&tiempo,&tiempo2,&res);
	printf("segundos: %ld\n", res.tv_sec);
	printf("Microsegundos: %ld\n", res.tv_usec);
	char* port=inet_ntoa(direccionForanea.sin_addr);
	p.inicializaIp(port);
	p.inicializaPuerto(ntohs(direccionForanea.sin_port));
	if(n < 0)
	{
		if(errno == EWOULDBLOCK)
			cout << "Tiempo de recepcion transcurrido" <<  endl;
		else
			cout << "Error  en recvfrom" << endl;
	}
	return n;
}

