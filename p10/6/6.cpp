#include <iostream>
#include <unistd.h>
#include <thread>
#include <cstdlib>
#include <mutex>

using namespace std;

int global = 0;
mutex m;

void 
plus_t(int n)
{
  m.lock();
  for (int i = 0; i < n;i++)
  {
    global++;
  }
  m.unlock();
}

void 
minus_t(int n)
{
  m.lock();
  for (int i = 0; i < n;i++)
  {
    global--;
  }
  m.unlock();
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

