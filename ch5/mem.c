#include <stdlib.h>
#include <stdlio.h>
#include <stddef.h>
#include <assert.h>
#include "mem.h"

void *Mem_alloc(long nbytes, const char *file, int line) {
  void *ptr;

  assert(nbytes > 0);
  ptr = malloc(nbytes);
  if (ptr == NULL) {
    fprintf(stderr, "mem alloc error in %s:%d\n", file, line);
  }

  return ptr;
}

void *Mem_calloc(long count, long nbytes, const char *file, int line) {
  void *ptr;

  assert(count > 0);
  assert(nbytes > 0);

  ptr = calloc(count, nbytes);
  if (ptr == NULL) {
    fprintf(stderr, "mem alloc error in %s:%d\n", file, line);
  }
  return ptr;
}

void Mem_free(void *ptr, const char *file, int line) {
  if (ptr)
    free(ptr);
}
