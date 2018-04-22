all: fecha main
	./3
fecha: Fecha.h Fecha.cpp
	g++ Fecha.cpp -c
main: Fecha.o Programa_3_3.cpp
	g++ Programa_3_3.cpp Fecha.o -o 3
