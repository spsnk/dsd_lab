#include "PoligonoIrreg.h"


size_t PoligonoIrreg::Polig_numero_veces = 0;

PoligonoIrreg::PoligonoIrreg (void)
{
  //vertice.reserve (10);
}

PoligonoIrreg::PoligonoIrreg (size_t n)
{
  vertice.reserve (n);
  for(size_t i = 0; i < n; i++)
  {
    anadeVertice();
  }
}

bool
PoligonoIrreg::anadeVertice (Coordenada v)
{
  vertice.push_back (v);
  return true;
}

bool
PoligonoIrreg::anadeVertice ( void )
{
  vertice.push_back (Coordenada (rand()%100, rand()%100));
  Polig_numero_veces++;
  return true;
}

void
PoligonoIrreg::imprimeVertices (void)
{
for (Coordenada v:vertice)
    {
      std::cout << "(" << v.obtenerX () << "," << v.	obtenerY () << ")" << std::endl;
    }
}

