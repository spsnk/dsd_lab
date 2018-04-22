#include <iostream>
#include <unistd.h>
#include <thread>
#include <cstdlib>

using namespace std;

int global = 0;

void 
plus_t(int n)
{
  for (int i = 0; i < n;i++)
  {
    global++;
  }
  sleep(1);
}

void 
minus_t(int n)
{
  for (int i = 0; i < n;i++)
  {
    global--;
  }
  sleep(1);
}

int 
main(int argc, char* argv[])
{
  if(argc < 2)
  {
    return 1;
  }
  int n = atoi(argv[1]);
  printf("Proceso principal espera que los hilos terminen. \n");  
  thread th1(plus_t, n), th2(minus_t, n);
  th1.join();
  th2.join();
  printf("Valor final de la variable global %d. \n",global);
  exit(0);
}

