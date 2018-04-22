#include <iostream>
#include "Coordenada.h"
#include "Rectangulo.h"
  
using namespace std;
 
int main(){

	Rectangulo rectangulo1(2,3,5,1);
	
	double ancho, alto;   

	cout << "\nCalculando el área de un rectángulo dadas sus coordenadas en un plano cartesiano: \n";      
	
	rectangulo1.imprimeEsq();

	alto  = rectangulo1.obtieneSupIzq().obtenerY() - rectangulo1.obtieneInfDer().obtenerY();
	ancho = rectangulo1.obtieneInfDer().obtenerX() - rectangulo1.obtieneSupIzq().obtenerX();

	cout << "\n\tEl área del rectángulo es = " << ancho*alto << endl << endl;

	return 0;
}

