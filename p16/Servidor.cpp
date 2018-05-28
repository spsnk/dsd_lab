#include <cstdlib>
#include <string>
#include "Respuesta.h"

using namespace std;

char * reverse (char * data)
{
  string return_data (" "), word;
  size_t size_data = strlen(data);
  for (size_t i = 0;i < size_data+1;i++)
  {
    unsigned char c = data[i];
    switch (c)
    {
      default:
        word += c;
        break;
      case '\0':
      case '\n':
      case ' ':
        if(!word.empty ())
        {
          word += ' ';
          return_data.insert (0, word);
          word.clear();
        }
        break;
    }
  }
  char * resp = (char*)malloc (size_data);
  memcpy (resp,return_data.c_str(),size_data);
  return resp;
}

int main() {

	Respuesta respuesta(7200);
	
	while(1) {
		struct mensaje msj;
		cout << "while" << endl;
		//msj = respuesta.getRequest();
		memcpy(&msj, respuesta.getRequest(), sizeof(struct mensaje));
		cout << "id: " << msj.operationId << endl;
		switch(msj.operationId) {
			case 1:
				cout << "Id checado= 1" << endl;
				cout << "argumentos: " << msj.arguments << endl;
				
				respuesta.sendReply(reverse(msj.arguments),&msj.IP[0], msj.puerto);
				break;
			default:
				cout << "Error en el numero de operación" << endl;
				cout << "numero: " << msj.operationId << endl;
				exit(-1);
		}
	}
	

	return 0;
}
