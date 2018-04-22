#include <stdlib.h>
#include <iostream>

using namespace std;


class Fecha {
	private:
    	static int dia;
	    static int mes;
    	static int anio;
    	static int vecesMuestF;
	public:
    	static int getVecesMuestF();    
	    Fecha(int = 3, int = 4, int = 2014);
    	void inicializaFecha(int, int, int);
	    void muestraFecha();

		static int getDia();
		static int getMes();
		static int getAnio();
};

int Fecha::vecesMuestF = 0;

int Fecha::dia = 0;
int Fecha::mes = 0;
int Fecha::anio = 0;

int Fecha::getVecesMuestF(){
	return vecesMuestF;
}

int Fecha::getDia(){
	return dia;
}

int Fecha::getMes(){
	return mes;
}

int Fecha::getAnio(){
	return anio;
}

Fecha::Fecha(int dd, int mm, int aaaa){
	mes = mm;
    dia = dd;
    anio = aaaa;
}

void Fecha::inicializaFecha(int dd, int mm, int aaaa) {
    anio = aaaa;
    mes = mm;
    dia = dd;

    return;
}

void Fecha::muestraFecha(){    
	
	cout << "La fecha es(dia-mes-año): " << dia << "-" << mes << "-" << anio << endl;   
	vecesMuestF++;   

    return;
}

int main() {

    Fecha a, b, c(21, 9, 2000);
    b.inicializaFecha(17, 6 , 2000);
    a.muestraFecha();
    cout << "\nSe ha mandado llamar muestraFecha() " << a.getVecesMuestF() << " veces\n";
    cout << "DIA  estatico = " << a.getDia() << endl;
    cout << "MES  estatico = " << a.getMes() << endl;
    cout << "ANIO estatico = " << a.getAnio() << endl << endl;
    
	b.muestraFecha();   
    cout << "\nSe ha mandado llamar muestraFecha() " << b.getVecesMuestF() << " veces\n" << endl;   

    c.muestraFecha();
    cout << "\nSe ha mandado llamar muestraFecha() " << c.getVecesMuestF() << " veces\n" << endl;
    
    return 0;

}
