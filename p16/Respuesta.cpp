#include "SocketDatagrama.h"
#include "Respuesta.h"

Respuesta::Respuesta(int pl) {

	socketlocal = new SocketDatagrama(pl);

}

struct mensaje * Respuesta::getRequest() {

	struct mensaje* palabras;
	PaqueteDatagrama paq(sizeof(mensaje));
	socketlocal->recibe(paq);
	palabras = (struct mensaje*) paq.obtieneDatos();
	cout << "id: " <<  palabras->operationId << endl;
	cout << "argumentos: " <<  palabras->arguments << endl;
	
	return palabras;
}

void Respuesta::sendReply(char * respuesta, char * ipCliente, int puertoCliente) {

	PaqueteDatagrama paq(respuesta, sizeof(mensaje), ipCliente, puertoCliente);
	socketlocal->envia(paq);

}
