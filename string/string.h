typedef struct {
  char* data;
  int length;
} string;

string* str_cre(char* str);
string* str_cha(string* old_str, char* data);
void str_free(string** str);
int get_len(char* str);
