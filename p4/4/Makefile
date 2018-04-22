all: rectangulo coordenada main

rectangulo: Rectangulo.h Rectangulo.cpp
	g++ Rectangulo.cpp -c

coordenada: Coordenada.h Coordenada.cpp
	g++ Coordenada.cpp -c

main: Rectangulo.o Coordenada.o Prog4_1.cpp
	g++ Prog4_1.cpp Rectangulo.o Coordenada.o -o Prog4_1
