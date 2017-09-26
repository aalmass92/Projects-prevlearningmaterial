#include <stdio.h>  // adding header files to use  basic functions etc: printf

#define COUNT 100 // named constant defining number of prime number to be displayed ect: 100 numbers

unsigned int primes[COUNT]; // store 100 prime values

int PrimeCount = 2; // variable delclaration and assignment. It keeps track the no. of primes 
int PrimeCandidate = 3; // variable delclaration and assigment. It has the value of a number which may or may not be prime

int main(void) // does not take any argument, return an integer
{
  int i;  // loop control variable

  primes[0] = 1;// first prime number
  primes[1] = 2;// second prime number
  
while (PrimeCount < COUNT) //This is outer loop to run for first 100 prime number
    {
      for ( i=1 ; i<PrimeCount ; i++ )// inner loop  
	{
	  if ( PrimeCandidate % primes[i] == 0 )// if its true it will break out of loop. if its false it will come back to the loop
	    break; // takes control out of the loop
	} // end of for loop
     
      if ( i == PrimeCount ) // we did not break, this is a prime if condition is true
	{
	  primes[PrimeCount++] = PrimeCandidate;   // we add number into the array of prime numbers
	}// end of if
      PrimeCandidate++; // primecandidate + 1
    }// end of while loop

 printf("The first 100 prime numbers are: \n"); //display
  // display the primer numbers
 for ( i=0 ; i<COUNT ; i++ ) // excutes what ever the value count is 
   printf ("%d ",primes[i]);// displays prime numbers
  
 printf ("\n");
 return 0; // successful exit
}
