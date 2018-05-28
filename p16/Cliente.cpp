#include "Solicitud.h"
#include <iostream>

using namespace std;

int main() {

	char arreglo[100] = "Palabras a lo random para probar el programa que mas pongo";
	char ip[16];
	int puerto;
	int operacion = 1;
	cout << "Ingresa la IP : " << endl;
	cin >> ip;
	cout << "Ingresa el puerto del servidor:" << endl;
	cin >> puerto;

	Solicitud cliente;

	printf("La respuesta del servidor es <%s>\n", cliente.doOperation(ip, puerto, operacion, arreglo));

	return 0;
}