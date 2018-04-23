/* Archivo rand.x */

program RAND_PROG {
   version RAND_VERS {
      void INICIALIZA_RANDOM(long) = 1;
      double OBTIENE_SIGUIENTE_RANDOM(void) = 2;
	  void INICIALIZA_N1(int) = 3;
	  void INICIALIZA_N2(int) = 4;
	  int SUM(int) = 5;
	  int MUL(int) = 6;
   } = 1;
} = 0x31111111;

