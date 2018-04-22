#include "PaqueteDatagrama.h"   // Comillas pra indicar que la interfaz (biblioteca) esta en la misma carpeta
#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;

/*Constructores*/
PaqueteDatagrama::PaqueteDatagrama (unsigned int tam) { //Crea mensaje vacio de longitud tam
  datos = new char[tam + 1];
  longitud = tam;
}

                                /*(datos, longitud, IP envío, puerto envío) */
PaqueteDatagrama::PaqueteDatagrama (char *msj, unsigned int tam, char *IP,
                                    int pto) {
  datos = new char[tam + 1];
  longitud = tam;
  memcpy (datos, msj, longitud);        //Se llena el mensaje
  strcpy (ip, IP);
  puerto = pto;
}

//Destructor: Borrar los datos
PaqueteDatagrama::~PaqueteDatagrama () {
  delete[]datos;
}

char *
PaqueteDatagrama::obtieneDireccion () {
  return ip;
}

unsigned int
PaqueteDatagrama::obtieneLongitud () {
  return longitud;
}

int
PaqueteDatagrama::obtienePuerto () {
  return puerto;
}

char *
PaqueteDatagrama::obtieneDatos () {
  return datos;
}

/*Para el primer constructor*/
void
PaqueteDatagrama::inicializaDatos (char *msj) {
  memcpy (datos, msj, longitud);
}

void
PaqueteDatagrama::inicializaPuerto (int pto) {
  puerto = pto;
}

void
PaqueteDatagrama::inicializaIp (char *IP) {
  strcpy (ip, IP);
}
