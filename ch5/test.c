#include <stdio.h>

union align {
  int i;
  long l;
  long *lp;
  void *p;
  void (*fp)(void);
  float f;
  double d;
  long double ld;
};

int main(int argc, char *argv[])
{
  union align aa;
  printf("size of aa->l = %ld\n", sizeof(aa.l));
  printf("size of aa->p %ld\n", sizeof(aa.p));
  printf("size of aa-> fp %ld\n", sizeof(aa.fp));
  printf("size of aa->ld = %ld\n", sizeof(aa.ld));
 printf("%ld\n", sizeof(aa));
  return 0;
}

