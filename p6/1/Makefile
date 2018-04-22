all:	main
	./main 10
polig:	PoligonoIrreg.h PoligonoIrreg.cpp
	g++ PoligonoIrreg.cpp -c
coordenada:	Coordenada.h Coordenada.cpp
	g++ Coordenada.cpp -c
main:	PoligonoIrreg.o Coordenada.o main.cpp
	g++ main.cpp PoligonoIrreg.o Coordenada.o -o main
clean:
	rm -f *.o main *~
