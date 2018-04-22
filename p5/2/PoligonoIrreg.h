#ifndef __POLIGONO_H__
#define __POLIGONO_H__
#include "Coordenada.h"
#include <vector>
#include <iostream>
#include <cstdlib>

class PoligonoIrreg
{
	private:
		std::vector <Coordenada> vertice;
		static size_t Polig_numero_veces;
	public:
		PoligonoIrreg (void);
		PoligonoIrreg (size_t);
		bool anadeVertice(void);
		bool anadeVertice(Coordenada);
		void imprimeVertices(void);
};

#endif
