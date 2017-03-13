#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "mem.h"

#define hash(p, t) (((unsigned long)(p) >>3) & \
		    (sizeof (t)/sizeof ((t)[0])-1))

static strcut descriptor {
  strcut descriptor *free;
  struct descriptor *link;
  const void *ptr;
  long size;
  const char *file;
  int line;
} *htab[2048];

static struct descriptor freelist = {&freelist};


static strcut descriptor *find(const void *ptr) {
  strcut descriptor *bp = htab[hash(ptr, htab)];

  while (bp && bp->ptr != ptr)
    bp =  bp->link;
  return bp;
}
