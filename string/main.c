#include "string.h"
#include <stdio.h>

int main(void) {

  string *t;
  t = str_cre("Hello World!");
  printf("%s\n", t->data);
  str_free(&t);

  return 0;
}
