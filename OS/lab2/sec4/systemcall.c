#include <stdio.h> /* includes functions like  printf */

main ()
{

  int c,n =0; /*c and n local variables and  n is 0 */

  while (( c = getchar()) != 'Q' ) /* while loop  having a condition to exit when typed the character Q */
    printf(" char %3d is character %c with ascii code %d\n", n++, c,c);

  /*print how many character you typed in, spiting out which character than converting it to an ascii code   */
}
