#include 

extern int functionA(int a, int b, int c, int d, int e, int f, int g, int h);

int x = 0xcccc;
int y = 0xdddd;
int z = 0xeeee;

int
functionB(int a, int b, int c, int d, int e, int f)
{
  return a+b+c+d+e+f;
}

int
main (int argc, char **argv)
{
  volatile int k = 0xa5a5a5a5;
  k = functionA(0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88);

  printf ("%d\n", k); 
}
