#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>


int puerto = 7200;

int main(void)
{
   struct sockaddr_in msg_to_server_addr, client_addr;
   int s, num[2], res, posicion = 1;
   s = socket(AF_INET, SOCK_DGRAM, 0);
   /* rellena la dirección del servidor */
   bzero((char *)&msg_to_server_addr, sizeof(msg_to_server_addr));
   msg_to_server_addr.sin_family = AF_INET;
   //inet_addr convierte  la  direccion cp (IPV4 numeros y puntos) en un dato  binario en un  byte de 
   msg_to_server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
   //127.0.0.1 es el localhost
   msg_to_server_addr.sin_port = htons(puerto);
   /* rellena la direcciòn del cliente*/
   bzero((char *)&client_addr, sizeof(client_addr));
   client_addr.sin_family = AF_INET;
   client_addr.sin_addr.s_addr = INADDR_ANY;
   
   /*cuando se utiliza por numero de puerto el 0, el sistema se encarga de asignarle uno */
   client_addr.sin_port = htons(0);
   bind(s, (struct sockaddr *)&client_addr,sizeof(client_addr));
   num[0] = 2;
   num[1] = 5; /*rellena el mensaje */
   sendto(s, (char *)num, 2 * sizeof(int), 0, (struct sockaddr *) &msg_to_server_addr, sizeof(msg_to_server_addr));
   
   /* se bloquea esperando respuesta */
   recvfrom(s, (char *)&res, sizeof(int), 0, NULL, NULL);
  printf("Servidor: %d.%d.%d.%d", 
         (int)(msg_to_server_addr.sin_addr.s_addr&0xFF), 
         (int)((msg_to_server_addr.sin_addr.s_addr&0xFF00)>>8),
         (int)((msg_to_server_addr.sin_addr.s_addr&0xFF0000)>>16),
         (int)((msg_to_server_addr.sin_addr.s_addr&0xFF000000)>>24)
         );
   printf(":%d\n", ntohs(msg_to_server_addr.sin_port));
   
   //printf("El servidro tiene una ip = %s\n",msg_to_client_addr.sin_addr.s_addr);
   printf("2 + 5 = %d\n", res);
   close(s);
}

