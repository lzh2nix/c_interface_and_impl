#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "arena.h"
#define T Arena_T
#define THRESHOLD 10
struct T {
  T prev;
  char *avail;
  char *limit;
};

static T freechunks;
static int nfree;

T Arena_new() {
  T arena = malloc(sizeof(*arena));

  if (arena == NULL) {
    fprintf(stderr, "ALLOC MEM FAILED\n");
    return NULL;
  }
  arena->prev = NULL;
  arena->limit = arena->avail = NULL;

  return arena;
}

void Arena_dispose(T *ap) {
  assert(ap && *ap);
  Arena_free(*ap);
  free(*ap);
  *ap = NULL;
}

void *Arena_alloc(T arena, long nbytes,const char *file,
		  int line){
  assert(arena);
  assert(nbytes > 0);

  // for memory align
  size_t ldsize = sizeof(long double);
  nbytes = (((nbytes + ldsize - 1) / ldsize) * ldsize);

  while(nbytes > arena->limit - arena->avail) {
    T ptr;
    char *limit;
    if ((ptr = freechunks) != NULL) {
      freechunks = freechunks->prev;
      nfree--;
      limit = ptr->limit;
    } else {
      long m = sizeof(struct T) + nbytes + 10 * 1024;
      ptr = malloc(m);
      if (ptr = NULL) {
	fprintf(stderr, "ALLOC MEM FAILED %s:%ld\n", file, line);
      }
      limit = (char *)ptr + m;
    }

    *ptr = *arena;
    arena->avail= (char *)((struct T *)ptr + 1);
    arena->limit = limit;
    arena->prev = ptr;
  }
  arena->avail += nbytes;
  return arena->avail - nbytes;
}

void Arena_free(T arena) {
  assert(arena);
  while(arena->prev) {
    struct T tmp = *arena->prev;
    if (nfree < THRESHOLD) {
      arena->prev->prev = freechunks;
      freechunks = arena->prev;
      nfree++;
      freechunks->limit = arena->limit;
    } else
      free(arena->prev);
    *arena = tmp;
  }
  assert(arena->limit == NULL);
  assert(arena->avail = NULL);
}
