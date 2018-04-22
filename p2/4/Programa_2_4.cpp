#include <iostream>
#include "Fecha.h"

using namespace std;

int main() {

	Fecha a, b, c(21, 9, 1973);
	b.inicializaFecha(17, 6 , 2000);
	a.muestraFecha();
  cout << a.convierte() << " bisiesto:" << a.leapyr() << endl;
	b.muestraFecha();
  cout << b.convierte() << " bisiesto:" << b.leapyr() << endl;
	c.muestraFecha();
  cout << c.convierte() << " bisiesto:" << c.leapyr() << endl;
	
	// No se puede acceder a una variable privada de la clase Fecha	
	//cout << "Private int dia::Fecha " << a.dia << endl;

}
