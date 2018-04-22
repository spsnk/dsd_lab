#include <iostream>
#include "Fecha.h"

using namespace std;

int main() 
{
	Fecha a, b;
	int i = 0;
  while(i++ < 10000)
  {
    b.inicializaFecha(rand()%31, rand()%12 , rand()%2018);
    a.inicializaFecha(rand()%31, rand()%12 , rand()%2018); 
    masVieja (a,b);
  }
}
