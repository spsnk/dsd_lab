#include "Coordenada.h"

using namespace std;

Coordenada::Coordenada (double xx, double yy):x (xx),y (yy){ 
  m = sqrt(x*x+y*y);
}

double
Coordenada::obtenerX (void)
{
  return x;
}

double
Coordenada::obtenerY (void)
{
  return y;
}

double
Coordenada::getMagnitude (void)
{
  return m;
}

bool Coordenada_compara (Coordenada a, Coordenada b)
{
  return a.getMagnitude() < b.getMagnitude();
}
