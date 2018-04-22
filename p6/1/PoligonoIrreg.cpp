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
  double x, y;
  x = (-100) + static_cast <double> (rand()) /( static_cast <double> (RAND_MAX/(100+100)));
  y = (-100) + static_cast <double> (rand()) /( static_cast <double> (RAND_MAX/(100+100)));
  vertice.push_back (Coordenada (x, y));
  Polig_numero_veces++;
  return true;
}

void
PoligonoIrreg::imprimeVertices (void)
{
  std::vector<Coordenada>::iterator it = vertice.begin();
  std::cout.precision(3);
  std::cout << std::fixed;
  do{
    std::cout << "P:(" << (*it).obtenerX () << "," << (*it).obtenerY () << ")\tM: " << (*it).getMagnitude() << std::endl;
  } while (++it != vertice.end() );
  
  /*
  for (Coordenada v:vertice)
    {
      std::cout << "(" << v.obtenerX () << "," << v.	obtenerY () << ")" << std::endl;
    }
  */
}

void
PoligonoIrreg::ordenaA (void)
{
  std::sort(vertice.begin(), vertice.end(), Coordenada_compara);
}

