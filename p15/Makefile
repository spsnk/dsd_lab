all:	main
	./main 9000
gfx.o:	gfx.c gfx.h
	gcc -c gfx.c -o obj/gfx.o -lX11
SocketDatagrama.o:	SocketDatagrama.h SocketDatagrama.cpp
	g++ -c SocketDatagrama.cpp -Wall
PaqueteDatagrama.o:	PaqueteDatagrama.h PaqueteDatagrama.cpp
	g++ -c PaqueteDatagrama.cpp -Wall
main:	gfx.o SocketDatagrama.o PaqueteDatagrama.o main.cpp 
	g++ -o main main.cpp gfx.o PaqueteDatagrama.o SocketDatagrama.o