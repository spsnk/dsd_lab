all:	server
	./main 9000
gfx.o:	gfx.c gfx.h
	gcc -c gfx.c -o gfx.o -lX11
SocketDatagrama.o:	SocketDatagrama.h SocketDatagrama.cpp
	g++ -c SocketDatagrama.cpp -Wall
PaqueteDatagrama.o:	PaqueteDatagrama.h PaqueteDatagrama.cpp
	g++ -c PaqueteDatagrama.cpp -Wall
server:	gfx.o SocketDatagrama.o PaqueteDatagrama.o server.cpp 
	g++ -o main server.cpp gfx.o PaqueteDatagrama.o SocketDatagrama.o -lX11
clean:
	rm -f *.o *.exe main *~
