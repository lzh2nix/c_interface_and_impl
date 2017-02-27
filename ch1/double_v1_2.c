#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <string.h>

int linenum;

int getword(FILE *, char *, int);
void doubleworld(char *, FILE *);

int main(int argc, char *argv[]) {
  int i;
  for(i = 1; i < argc; i++) {
    FILE *fp = fopen(argv[i], "r");
    if (fp == NULL) {
      fprintf(stderr, "%s: can't open '%s' (%s)\n", argv[0], argv[i], strerror(errno));
      return EXIT_FAILURE;
    }
    else {
      doubleworld(argv[i], fp);
      fclose(fp);
    }
  }
  
  if (argc == 1)
    doubleworld(NULL, stdin);
}

int getword(FILE *fp, char *buf, int size) {
  int c;
  
  c = getc(fp);
  for (; c != EOF && isspace(c); c= getc(fp))
    if (c == '\n')
      linenum++;
  int i = 0;
  for (; c != EOF && !isspace(c); c = getc(fp)) {
    if (i < size -1)
      buf[i++] = tolower(c);
  }
  if (i < size)
    buf[i] = '\0';

  if (c != EOF)
    ungetc(c, fp);
  return buf[0] != '\0';
}


void print(char *filename, char *word, int count) {
  if (filename)
    printf("%s:", filename);
  printf("%d:%s:%d\n", linenum, word, count);
}
void doubleworld(char *name, FILE *fp) {
  char prev[128], word[128];

  linenum = 1;
  prev[0] = '\0';

  int count = 1;
  while(getword(fp, word, sizeof word)) {
    if (isalpha(word[0]) && strcmp(prev, word) == 0) {
      count++;
      continue;
    }

    if (count >= 2) {
      print(name, prev, count);
    }
    count = 1;
    strcpy(prev, word);
  }
}
