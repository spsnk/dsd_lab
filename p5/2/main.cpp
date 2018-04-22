#include <iostream>
#include "PoligonoIrreg.h"
#include <vector>
#include <cstdlib>

using namespace std;

int
main (int argc, char* argv[])
{
  if (argc < 3)
    return -1;
  vector <PoligonoIrreg> poligono;
  size_t num_polig = atoi(argv[1]);
  size_t num_vert = atoi(argv[2]);
  
  poligono.reserve(num_polig);
  
  for(size_t i = 0; i < num_polig; i++ )
  {
    PoligonoIrreg t(rand()%num_vert+1);
    poligono.push_back(t);
  }
  
  return 0;
}
