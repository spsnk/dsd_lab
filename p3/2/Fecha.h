#ifndef FECHA_H_
#define FECHA_H_

class Fecha {
	private:
		int dia;
		int mes;
		int anio;

public:
	Fecha(int = 3, int = 4, int = 2014);
	int placeholder [9999];
	void inicializaFecha(int, int, int);
	void muestraFecha();
	int convierte();
	bool leapyr();
};

int masVieja(Fecha, Fecha);

int masViejaR(Fecha &, Fecha &);

#endif
