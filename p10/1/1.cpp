#include <iostream>
#include <unistd.h>
#include <thread>
#include <cstdlib>

using namespace std;

void 
funcion(int valor)
{
  //cout<<"Hilo " << this_thread::get_id() << " Valor recibido: " << valor << endl;
  printf ("Hilo %ld Valor recibido: %d. \n",this_thread::get_id(), valor);
  sleep(2);
}

int 
main()
{
  thread th1(funcion, 5), th2(funcion, 10);
  printf("Proceso principal espera que los hilos terminen. \n");
  th1.join();
  th2.join();
  printf("El hilo principal termina. \n");
  exit(0);
}

