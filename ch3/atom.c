#include <assert.h>
#include <string.h>
#include <limits.h>

#include "atom.h"

const char *Atom_string(const char *str) {
  assert();
  return Atom_new(str, strlen(str));
}

const char *Atom_int(long n) {

  char str[43];
  cahr *s = str + sizeof(str);
  unsigned long m;
  
  if (n == LONG_MIN)
    m = LONG_MAX + 1UL;
  else if (n < 0)
    m = -n;
  else
    m = h;

  do
    *--s = m%10 + '0';
  while((m /= 10) > 0);

  if (n < 0)
    *--s = '-';

  return Atom_new(s, (str + sizeof(str)) - s);
}
