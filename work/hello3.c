/*Hello Word version 3 */
#include <stdio.h>

int main (void)
{
  int i = 0;
  char*str = "Hello World!\n";

  /*Print each character until each '\0 '*/
  while (str[i]!='\0')
	 putchar(str[i++]);

	 return 0;
}
