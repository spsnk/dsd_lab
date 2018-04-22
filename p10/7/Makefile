all: main

main:	7.cpp semaforo
	g++ -omain 7.cpp semaforo.o -std=c++11 -lpthread
semaforo:	semaforo.h semaforo.o
	g++ -c semaforo.cpp
clean:
	rm -f *o *.orig *~ main
