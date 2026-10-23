#include "string.h"
#include <stdio.h>

void *string_memcpy(void *dest, const void *src, size_t length) {
  unsigned char *_dest = dest;
  const unsigned char *_src = src;

  for (size_t i = 0; i < length; ++i) {
    _dest[i] = _src[i];
  }

  return _dest;
}

string_t* string_init(char* str) {
  size_t length = string_length(str);
  string_t *new_string = calloc(length+1, sizeof(string_t));

  string_memcpy(new_string->data, str, length+1);
  // new_string->data[length] = '\0';
  
  return new_string;
}

int string_length(char* str) {
  if (str == NULL) {
    printf("The given char pointer is NULL.\n");
    return -1;
  }

  size_t position = 0;
  char current = str[position];

  while (str[position] != '\0') {
    ++position;
  }

  return position;
}

int main(void) { 
  char *hello = "hello";
  size_t length = string_length(hello);
  printf("The length of: %s is: %zu", hello, length);

  string_t *string = string_init(hello);
  printf("Set data: %s", string->data);

  return 0;
}
