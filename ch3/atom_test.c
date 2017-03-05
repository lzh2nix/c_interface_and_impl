#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "atom.h"
#define LEN 21

int main() {

  FILE *fp = fopen("1000_string.txt", "r");
  assert(fp);
  char *string;

  int i = 0;
  char teststring[LEN];
  while(fgets(teststring, LEN, fp)) {
    size_t len = strlen(teststring);
    teststring[len-1] = '\0';
    Atom_string(teststring);
    i++;
  }
  Atom_print();
  int dist[2048] = {0};
  Atom_getdist(dist, 2048);
  for (i = 0; i < 2048; i++) {
    if (dist[i] != 0)
      printf("%d---->%d\n",i, dist[i]);
  }
  char *str = "Vt34OI09fAyL1G";
  Atom_free(str);
  Atom_print();

  Atom_reset();

  Atom_print();
  fclose(fp);
}
