all:	main

main:	main.cpp archivo
	g++ -o main main.cpp archivo.o
archivo:	archivo.h archivo.cpp
	g++ -c archivo.cpp
clean:
	rm -f *.o main *.orig *~
