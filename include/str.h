#ifndef __stdlibc_str_h
#define __stdlibc_str_h

#include <stdlib.h>
#include <string.h>

#include "array.h"

#define str(s)             str_create(s)

typedef struct str_s {
    char* data;
    size_t length;
} str;

str* str_create(const char* data);  // create a string from a c string

void str_destroy(str* s);

void str_append(str* s, str* append);
void str_append_cstr(str* s, const char* append);

array* str_split(str* s, str* delim);
array* str_split_cstr(str* s, const char* delim);

size_t str_length(str* s);

int str_start_with(str* s, str* prefix);
int str_start_with_cstr(str* s, const char* prefix);

int str_end_with(str* s, str* suffix);
int str_end_with_cstr(str* s, const char* suffix);

str* str_trim(str* s);

str* str_substring(str* s, size_t start, size_t end);

str* str_replace(str* s, str* old, str* new);
str* str_replace_cstr(str* s, const char* old, const char* new);

str* str_to_upper(str* s);
str* str_to_lower(str* s);

char* str_to_cstr(str* s);

#endif