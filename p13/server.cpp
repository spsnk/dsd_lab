#include <iostream>
#include <cstdlib>
#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include "data.h"

using namespace std;

int
main (int argc, char* argv[])
{
  if(argc < 2)
  {
    return 1;
  }
  
  int port = atoi(argv[1]);
  
  data msj, msj_client;
  char *ip_cliente;
  bool valid = true;
  
  SocketDatagrama server (port);
  PaqueteDatagrama pk_recv (sizeof (msj));
  
  while (1) {
    cout << "Waiting for client" << endl;
    int n = server.recibe (pk_recv);
    ip_cliente = pk_recv.obtieneDireccion ();
    int pto_cliente = pk_recv.obtienePuerto ();
    cout << "Packet received from " << ip_cliente << ":" << pto_cliente
      << endl;
    msj_client = *pk_recv.obtieneDatos ();
    cout << "Received:"<< endl;
    msj_client.print();
    cout << "Processing..." << endl;
    for(size_t i = msj_client.lower_limit; i < msj_client.upper_limit; i++ )
    {
      if ( (msj_client.number % i) == 0 ) 
      {
        valid = false;
        break;
      }
    }
  msj.valid = valid;
  msj.print();
  PaqueteDatagrama pk_send (&msj, sizeof (msj), ip_cliente, 3939);
  cout << "Enviando mensaje..." << endl;
  SocketDatagrama client (3939);
  int m = client.envia (pk_send);
  cout << "Mensaje enviado." << endl;
  }
  return 0;
}

