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
    
  char data [100];
  
  SocketDatagrama server (port);
  PaqueteDatagrama pk_recv (sizeof (data));
  
  gfx_open (800, 600, "Fourier");
  gfx_color (7, 242, 255);
  
  while (1)
  {
    cout << "Listening on port " << port << endl;
    int n = server.recibe (pk_recv);
    cout << "Packet received from " << pk_recv.obtieneDireccion () << ":" << pk_recv.obtienePuerto () << endl;
    memcpy(&data , pk_recv.obtieneDatos (), 100);
    cout << "Received data"<< endl;
    cout << data << endl;
    char *str1 = strtok(data, " ");
    char *str2 = strtok(NULL, " ");
    float x = atof ( str1 );
    float y = atof ( str2 );
    cout << "Drawing..." << endl; 
    cout << "x:" << x << "\ty:" << y << endl;
    gfx_point (x,y);
    gfx_flush ();
  }
  
  return 0;
}
