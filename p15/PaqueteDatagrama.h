#ifndef PAQUETEDATAGRAMA_H_
#define PAQUETEDATAGRAMA_H_

class PaqueteDatagrama {
private:
	//Almacena los datos
	char *datos;
	//Almacena la IP
	char ip[16];
	//Almacena la longitud de la cadena de datos
	unsigned int longitud;
	//Almacena el puerto
	int puerto;

public:
	/*Constructores*/
	
	PaqueteDatagrama(unsigned int); //Crea mensaje vacio de longitud tam
	PaqueteDatagrama(char *, unsigned int, char *, int ); /*(datos, longitud, IP envío, puerto envío)*/
	
	~PaqueteDatagrama(); //Destructor: Borrar los datos
	
	char *obtieneDireccion();
	unsigned int obtieneLongitud();
	int obtienePuerto();
	char *obtieneDatos();
	void inicializaPuerto(int);
	void inicializaIp(char *);
	void inicializaDatos(char *);		
};

#endif
