#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <fcntl.h>
#include <inttypes.h>
#include <time.h>

using namespace std;
int pto_server;

struct mensaje{
	uint32_t secuencia; //Numero de secuencia
	uint32_t solicitud[2];
	uint32_t respuesta;
}mensaje;


int main(int argc, char const *argv[])
{
	if(argc != 2)
	{
		cout << "Modo de ejecución  =  " << argv[0] << " - [Numero de n] " << endl;
	}

	int n = atoi(argv[1]);			
	pto_server = 7200;
	SocketDatagrama cliente(pto_server);
	//cliente.setTimeout(2,0);		
	string ip_server = "127.0.0.1";
	char ipaux[16];
	strcpy(ipaux, ip_server.c_str());
	mensaje.secuencia = 1;
	srand(time(NULL));
	//int num1 = 0, num2 = 0, flag = 0, p ,aux, contnoS = 0, contsiS = 0;

	while(mensaje.secuencia < n){		
		//num1 = 1 + rand() % (100-1);
		//num2 = 1 + rand() % (100-1);
		//mensaje.solicitud[0] = num1;
		//mensaje.solicitud[1] = num2;		

		PaqueteDatagrama pk_send((char*)&mensaje,sizeof(mensaje), ipaux, pto_server);
		p = cliente.envia(pk_send);

		PaqueteDatagrama pk_recv(sizeof(mensaje));
		aux = cliente.recibeTimeout(pk_recv);

		if(aux == -1){	
			mensaje.secuencia++;
			cout << "El servidor no respondio se reenviara " << endl;
			cout << "Secuencia = "  << mensaje.secuencia << endl;
			contnoS++;
			flag = 1;
			while(flag != 1)
			{
				PaqueteDatagrama pk_send((char*)&mensaje,sizeof(mensaje), ipaux, pto_server);
				p = cliente.envia(pk_send);

				PaqueteDatagrama pk_recv(sizeof(mensaje));
				aux = cliente.recibeTimeout(pk_recv);
				if(aux == -1)
				{
					mensaje.secuencia++;
					cout << "Secuencia = "  << mensaje.secuencia << endl;
					contnoS++;
				}
				else
				{
					flag = 0;
					break;
				}				
			}  
		}	

		if(aux != -1)
		{			
			cout << "Servidor encontrado" << endl;		
			contsiS++;
			cout <<  mensaje.respuesta  << endl;
			cout << mensaje.solicitud[0]<< " + " << mensaje.solicitud[1] << " = "
			<< mensaje.respuesta << endl;
			cout << "Secuencia = "  << mensaje.secuencia << endl;
			mensaje.secuencia++; 			
		}

	}
	cout << "Numero  de solicitudes distintas hechas al servidor = " << contnoS << endl;
	cout << "Numero  de solicitudes totales hechas al servidor = " << mensaje.secuencia << endl;
	cout << "Numero  de solicitudes respondidas por el servidor = " << contsiS << endl;

	exit(0);
	
}
