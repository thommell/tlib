#include <ctype.h>
#include <stdio.h>
#include <tstring.h>
#include <tlogger.h>

void *string_memcpy(void *destination, const void *source, size_t length) {
    //I have no idea why I did it like this, might change later :)
	unsigned char *dest = destination;
	const unsigned char *src = source;

	for (size_t i = 0; i < length; ++i) {
		dest[i] = src[i];
	}

	return dest;
}

void string_copy(string_t *dest, const string_t *src) {
    for (int i = 0; i < src->length; ++i) {
        dest[i] = src[i];
    }
}

int string_append(string_t *dest, const string_t *src) {
    size_t new_len = dest->length-1 + src->length;
    size_t original_len = dest->length;

    void *temp = realloc(dest->data, new_len);
    if (temp == NULL) {
        logm(ERROR, "Couldn't reallocate more memory. [TSTRING.C]");
        return -1;
    }

    dest = temp;

    size_t curr_src_pos = 0;
    size_t curr_dest_pos = original_len-1;

    while (curr_src_pos <= src->length) {
        dest->data[curr_dest_pos] = src->data[curr_src_pos];
        ++curr_src_pos;
        ++curr_dest_pos;
    }
    printf("%s", dest->data);


    return 0;
}

string_t* string_init(char* str) {
	size_t length = string_length(str);
	string_t *new_string = calloc(1, sizeof(string_t));
	new_string->data = calloc(length+1, sizeof(char));
	new_string->length = length;

	string_memcpy(new_string->data, str, length+1);

	return new_string;
}

int string_length(char* str) {
	if (str == NULL) {
		logm(WARN, "The given char pointer is NULL.");
		return -1;
	}

	size_t position = 0;
	char current = str[position];

	while (str[position] != '\0') {
		++position;
	}
    ++position;

	return position;
}

size_t string_count_char(string_t *str, char c) {
    size_t pos = 0, occurring = 0;

    if (str == NULL) {
        logm(WARN, "Given string is NULL.");
        return occurring;
    }

    while (pos < str->length) {
        char lower_c = tolower(c);
        char current_c = tolower(str->data[pos]);
        if (lower_c == current_c) {
            ++occurring;
        }
        ++pos;
    }

    return occurring;
}

void string_free(string_t** str) {
	if (*str == NULL) {
		logm(ERROR, "The given pointer is NULL - freeing failed.");
		return;
	}

	free((*str)->data);
	free(*str);
	*str = NULL;
}
