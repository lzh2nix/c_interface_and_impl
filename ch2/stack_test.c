#include <stdio.h>
#include "stack.h"

int main() {
  Stack_T stk = Stack_new();

  printf("---%p\n", stk);
  int array[4];
  array[0]  = 12;
  array[1]  = 13;
  array[2]  = 14;
  array[3]  = 15;
  Stack_push(stk, &array[0]);
  Stack_push(stk, &array[0]);
  
  Stack_push(stk, &array[0]);
  
}
