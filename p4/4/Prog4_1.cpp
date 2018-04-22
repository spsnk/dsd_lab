#include <iostream>
#include "Coordenada.h"
#include "Rectangulo.h"
  
using namespace std;
 
int main(){

	Rectangulo rectangulo1(3.6,0.98,5.10,0.195);
	
	double ancho, alto;   

	cout << "\nCalculando el área de un rectángulo dadas sus coordenadas en un plano cartesiano: \n";      
	
	rectangulo1.imprimeEsq();

	cout << "\n\tEl área del rectángulo es = " << rectangulo1.obtieneArea() << endl << endl;

	return 0;
}

