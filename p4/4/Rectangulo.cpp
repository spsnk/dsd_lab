#include "Rectangulo.h"

using namespace std;

Rectangulo::Rectangulo() : superiorIzq(0,0), inferiorDer(0,0){ }
Rectangulo::Rectangulo(double xSupIzq, double ySupIzq, double xInfDer, double yInfDer):superiorIzq(xSupIzq, ySupIzq), inferiorDer(xInfDer, yInfDer)
{ }

void Rectangulo::imprimeEsq(){
	cout << "\n\tPara la esquina superior izquierda.";
	cout << "x = " << superiorIzq.obtenerX() << " y = " << superiorIzq.obtenerY() << endl;
	cout << "\n\tPara la esquina inferior derecha.";
	cout << "x = " << inferiorDer.obtenerX() << " y = " << inferiorDer.obtenerY() << endl;   
}


Coordenada Rectangulo::obtieneSupIzq(){
	return superiorIzq;
}

Coordenada Rectangulo::obtieneInfDer(){
	return inferiorDer;
}

double Rectangulo::obtieneArea (void)
{
  double alto  = superiorIzq.obtenerY() - inferiorDer.obtenerY();
	double ancho = inferiorDer.obtenerX() - superiorIzq.obtenerX();
	return alto*ancho;
}
