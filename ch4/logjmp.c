#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>

int div_by_zero_handled = 0;
jmp_buf Div_Failed;

int test(int n, int m) {
  if (m == 0) {
    if (div_by_zero_handled) {
      longjmp(Div_Failed, 1);
    }
  }
  return n / n;
}

int main() {
  div_by_zero_handled = 1;
  if (setjmp(Div_Failed)) {
    printf("can't div by zero \n");
    exit(EXIT_FAILURE);
  }

  int n = test(2, 0);

  printf("----->%d\n", n);

  return 0;
}
