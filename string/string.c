#include "string.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 256

// @brief creates the string.
// @returns an allocated string*
string* str_cre(char* str) {
  string* s;

  s = malloc(sizeof(string));
  if (s == NULL) {
    printf("Allocating STR failed!");
    return NULL;
  }
  s->length = get_len(str);

  // +1 due to '\0' closing char
  s->data = malloc(sizeof(char) * s->length + 1);
  if (s->data == NULL) {
    printf("Allocating STR DATA failed!");
    return NULL;
  }

  for (int i = 0; i < MAX_LENGTH && str[i] != '\0'; ++i) {
    s->data[i] = str[i];
  }
  s->data[s->length] = '\0';

  return s;
}

// @brief changes the string to the value of new_data
// @returns string* filled with new_data
string* str_cha(string* str, char* new_data) {
  free(str->data);
  str->data = malloc(get_len(new_data) + 1);
  if (str->data == NULL) {
    printf("Allocating failed in STR_CHA");
    return NULL;
  }
  return str;
}

// @brief frees the string's allocated memory
void str_free(string** str) {
  free((*str)->data);
  free(*str);
  *str = NULL;
}

int get_len(char* str) {
  int len = 0;

  for (int i = 0; i < MAX_LENGTH && str[i] != '\0'; ++i) {
    len++;
  }
  
  return len;
}
