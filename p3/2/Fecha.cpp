#include "Fecha.h"
#include <iostream>

using namespace std;

Fecha::Fecha(int dd, int mm, int aaaa) {
	
	mes = mm;
	dia = dd;
	anio = aaaa;
}

void Fecha::inicializaFecha(int dd, int mm, int aaaa){
	
	anio = aaaa;
	mes = mm;
	dia = dd;

	return;
}

void Fecha::muestraFecha(){
	
	cout << "La fecha es(dia-mes-año): " << dia << "-" << mes << "-" << anio << endl;
	return;
}

int Fecha::convierte() {
  return anio*10000+mes*100+dia;
}

bool Fecha::leapyr()
{
  bool leap = false;
  if(anio%4==0 && anio%100!=0)
    leap = true;
  if(anio%400==0)
    leap = true;
  return leap;
}

int masViejaR(Fecha & f1, Fecha & f2)
{
  if (f1.convierte() > f2.convierte())
    return 1;
  if (f1.convierte() == f2.convierte())
    return 0;
  if (f1.convierte() < f2.convierte())
    return -1;
}

int masVieja(Fecha f1, Fecha f2)
{
  if (f1.convierte() > f2.convierte())
    return 1;
  if (f1.convierte() == f2.convierte())
    return 0;
  if (f1.convierte() < f2.convierte())
    return -1;
}
