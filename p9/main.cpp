#include <iostream>
#include "archivo.h"

int
main (int argc, char* argv[])
{
  if(argc != 3)
    {
      printf("Forma de uso: %s archivo_origen archivo_destino\n", argv[0]);
      exit(-1);
    }

  Archivo a (argv[1]);
  Archivo b (argv[2],O_WRONLY|O_TRUNC|O_CREAT, 0666);

  while( a.lee(BUFSIZ) > 0 );
  b.escribe( (void *) a.get_contenido(), a.obtieneNum_bytes() );
  return 0;
}
