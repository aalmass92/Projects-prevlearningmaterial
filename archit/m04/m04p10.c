#include <stdio.h>

void forever()
{
 long long counter = 0;
 while (1){
   counter++;
   printf("%lld\n",counter);
 }
}
 int main (int argc,char**argv)
 {
   forever();
 }
