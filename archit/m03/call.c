extern int x,y,z;

extern int functionB(int a, int b, int c, int d, int e, int f);

int
functionA(int a, int b, int c, int d, int e, int xx, int yy, int zz)
{
  int f;
  int g;
  int h;

  f=a+b;
  g=b-c;
  h=d*e;
  e=functionB(f,g,h,x,y,z);
  return (e+xx+yy+zz);
}
