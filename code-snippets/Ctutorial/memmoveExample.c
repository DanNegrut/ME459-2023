#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct my_struct {
  unsigned int counter;
  float average;
  unsigned int in_use;
};

int main() {
  /* allocating a struct with malloc() */
  struct my_struct *s = NULL;
  s = (struct my_struct *)malloc(sizeof(*s)); /* NOT sizeof(s)!! */
  if (s == NULL) {
    printf("no memory !\n");
    exit(1);
  }

  memset(s, 0, sizeof(*s));

  /* another way to initialize an alloc’d structure: */
  struct my_struct init = {1, 2.5, 1};

  /* memmove(dst, src, size) (note, arg order like assignment) */
  memmove(s, &init, sizeof(init));

  /* when you are done with it, free it! */
  free(s);
  s = NULL;
  return 0;
}
