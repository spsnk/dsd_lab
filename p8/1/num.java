import java.util.*;
import java.lang.Math;

public class num {
public static void main(String args[])
{
  double seno = 0;
  double coseno = 0;
  double tangente = 0;
  double logaritmo = 0;
  double raizc = 0;
  for (double i = 0; i < 30000000; i++)
  { 
    seno += Math.sin(i);
    coseno += Math.cos(i);
    tangente += Math.tan(i);
    logaritmo += Math.log10(i);
    raizc += Math.sqrt(i);
  }
}

}
