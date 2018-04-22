#include <iostream>
#include <cmath>

int main (int argc, char* argv[])
{
  double seno = 0;
  double coseno = 0;
  double tangente = 0;
  double logaritmo = 0;
  double raizc = 0;
  for(double i = 0; i < 30000000; i++)
  {
    seno += sin(i);
    coseno += cos(i);
    tangente += tan(i);
    logaritmo += log10(i);
    raizc += sqrt(i);
  }
  return 0;
}
