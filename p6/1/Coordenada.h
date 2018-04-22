#ifndef COORDENADA_H_
#define COORDENADA_H_

#include <iostream>
#include <cmath>

class Coordenada{

	private:
		double x;     
		double y;
		double m;
  
	public:
		Coordenada(double = 0, double = 0);
		double obtenerX(void);
		double obtenerY(void);
		double getMagnitude(void);
};

bool Coordenada_compara (Coordenada, Coordenada);

#endif
