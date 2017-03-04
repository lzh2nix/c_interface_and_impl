#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "atom.h"
#define LEN 21

int main() {

  FILE *fp = fopen("1000_string.text", "r");
  assert(fp);
  char *string;

  int i = 0;
  char teststring[LEN];
  while(fgets(teststring, LEN, fp)) {
    Atom_string(teststring);
    i++;
  }
  int dist[2048] = {0};
  Atom_getdist(dist, 2048);
  for (i = 0; i < 2048; i++) {
    printf("%d\n", dist[i]);
  }
  fclose(fp);
}
