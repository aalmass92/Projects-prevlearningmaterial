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
printf("+---------+------------+\n");
printf("| Celsius | Fahrenheit |\n");
printf("+---------+------------+\n");

  /* Create conversion table using the equation: F = (9/5)*cel+(32) */
  cel = lower;
  while (cel <= upper) {
         fahr = ((9.0/5.0) * (cel))+(32.0);
         printf("|\t%3.0f|\t %6.1f|\n", cel, fahr);
	 printf("+----------+-----------+\n");
         cel += step;
  }
  
}

