#include <iostream>
#include "PoligonoIrreg.h"
#include <vector>
#include <cstdlib>

using namespace std;

int
main (int argc, char* argv[])
{
  if (argc < 2)
    return -1;
  
  size_t num_vert = atoi(argv[1]);
  
  PoligonoIrreg poligono(num_vert);
  
  poligono.imprimeVertices();

  poligono.ordenaA();
  
  cout << "Ordenadas" << endl;
  
  poligono.imprimeVertices();
  
  return 0;
}
