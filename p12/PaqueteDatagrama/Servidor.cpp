#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"    // Comillas pra indicar que la interfaz (biblioteca) esta en la misma carpeta
#include <iostream>
#include <cstdlib>
using namespace std;

int puerto = 7200;

int
main (void) {
  char msj[50], msj_cliente[50];
  SocketDatagrama servidor (puerto);
  PaqueteDatagrama pk_recv (sizeof (msj));

  cout << "Servidor iniciado... Esperando clientes" << endl;

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
