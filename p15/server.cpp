#include <iostream>
#include "gfx.h"
#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"

using namespace std;

int
main (int argc, char* argv[])
{
  if(argc < 1)
  {
    cout << "Not enough arguments." << endl;
    return 1;
  }
  
  int port = atoi(argv[1]);
    
  char data [50];
  
  SocketDatagrama server (port);
  PaqueteDatagrama pk_recv (sizeof (msj));
  
  gfx_open (800, 600, "Fourier");
  gfx_color (7, 242, 255);
  
  while (1)
  {
    cout << "Listening on port " << port << endl;
    int n = server.recibe (pk_recv);
    cout << "Packet received from " << pk_recv.obtieneDireccion () << ":" << pk_recv.obtienePuerto () << endl;
    data = *pk_recv.obtieneDatos ();
    cout << "Received data"<< endl;
    float x = atof (strtok(data, " ,") );
    float y = atof (strtok(NULL, " ,") );
    cout << "Drawing..." << endl;
    cout << "x:" << x << endl << "y:" << y << endl;
    gfx_point (x,y);
    gfx_flush ();
  }
  
  return 0;
}
