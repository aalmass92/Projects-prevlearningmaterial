/*Celcius to Farenheit conversion table (K&R page 12) */
#include <stdio.h>

int main(void)
{
  float fahr, cel;
  int lower, upper, step;

  /* Set lower and upper limits of the temperture table (in Celcius) along with the 
   * table increment step-size */
  lower = -40;
  upper = 240;
  step = 10;

  /* Create conversion table using the equation: F = (9/5)*cel+(32) */
  cel = lower;
  while (cel <= upper) {
         fahr = ((9.0/5.0) * (cel))+(32.0);
         printf("%3.0f \t%6.1f\n", cel, fahr);
         cel += step;
  }
}
    
