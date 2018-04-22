#include <iostream>
#include "Fecha.h"

using namespace std;

int main() {

	Fecha a, b, c(21, 9, 1973);
	b.inicializaFecha(17, 6 , 2000);
	a.muestraFecha();
	b.muestraFecha();
	c.muestraFecha();

	
	// No se puede acceder a una variable privada de la clase Fecha	
	//cout << "Private int dia::Fecha " << a.dia << endl;

}
