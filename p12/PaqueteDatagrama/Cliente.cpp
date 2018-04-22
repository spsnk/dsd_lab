#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int pto_servidor = 7200;

int
main (void) {
  char msj[50], msj_servidor[50];
  SocketDatagrama cliente (pto_servidor);
  //Datos de la conexión para el paquete
  string ip_server = "127.0.0.1";
  char ipaux[16];
  strcpy (ipaux, ip_server.c_str ());

  PaqueteDatagrama pk_send ((char *) &msj, sizeof (msj), ipaux, pto_servidor);
  int byt_env;


  while (1) {
    int n = servidor.recibe (pk_recv);
    char *ip_cliente = pk_recv.obtieneDireccion ();
    int pto_cliente = pk_recv.obtienePuerto ();
    cout << "Mensaje recibido de cliente " << ip_cliente << ":" << pto_cliente
      << endl;
    cout << ">> " << pk_recv.obtieneDatos () << endl;
    PaqueteDatagrama pk_send ((char *) msj_cliente, sizeof (msj_cliente),
                              ip_cliente, pto_cliente);
    cout << "Enviando mensaje..." << endl;
    int m = servidor.envia (pk_send);
  }

  return 0;
}
