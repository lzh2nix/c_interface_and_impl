#include <stdio.h>
#include "stack.h"

int main() {
  Stack_T stk = Stack_new();

  int array[4];
  array[0]  = 12;
  array[1]  = 13;
  array[2]  = 14;
  array[3]  = 15;
  Stack_push(stk, &array[0]);
  Stack_push(stk, &array[1]);  
  Stack_push(stk, &array[2]);
  Stack_push(stk, &array[3]);

  int i = 0;
  for (; i < 4; i ++) {
    int *v = (int *)Stack_pop(stk);
    printf("----%d\n", *v);
  }

  return 0;
}
