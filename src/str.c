#include "str.h"
#include "array.h"
#include <stdlib.h>
#include <string.h>

str* str_create(const char* data) {
    str* s = (str *)malloc(sizeof(str));
    s->length = strlen(data);
    s->data = (char *)malloc(s->length + 1);
    strcpy(s->data, data);
    return s;
}

void str_destroy(str* s) {
    free(s->data);
    free(s);
}

void str_append(str* s, str* append) {
    s->data = (char *)realloc(s->data, s->length + append->length + 1);
    strcat(s->data, append->data);
    s->length += append->length;
}

void str_append_cstr(str* s, const char* append) {
    int len = strlen(append);
    s->data = (char *)realloc(s->data, s->length + len + 1);
    strcat(s->data, append);
    s->length += len;
}

array* str_split(str* s, str* delim) {
    return str_split_cstr(s, delim->data);
}

array* str_split_cstr(str* s, const char* delim) {
    array* result = array_create(sizeof(str*));
    char* p = strtok(s->data, delim);
    while (p != NULL) {
        str* tmp = str(p);
        array_push_back(result, tmp);
        p = strtok(NULL, delim);
    }
    return result;
}

size_t str_length(str* s) {
    return s->length;
}

int str_start_with(str* s, str* prefix) {
    return strncmp(s->data, prefix->data, prefix->length) == 0;
}

int str_start_with_cstr(str* s, const char* prefix) {
    return strncmp(s->data, prefix, strlen(prefix)) == 0;
}

int str_end_with(str* s, str* suffix) {
    if (s->length < suffix->length) {
        return 0;
    }
    return strncmp(s->data + s->length - suffix->length, suffix->data, suffix->length) == 0;
}

int str_end_with_cstr(str* s, const char* suffix) {
    int len = strlen(suffix);
    if (s->length < len) {
        return 0;
    }
    return strncmp(s->data + s->length - len, suffix, len) == 0;
}

str* str_trim(str* s) {
    int start = 0;
    while (start < s->length && (s->data[start] == ' ' || s->data[start] == '\t' || s->data[start] == '\n')) {
        start++;
    }
    int end = s->length - 1;
    while (end >= 0 && (s->data[end] == ' ' || s->data[end] == '\t' || s->data[end] == '\n')) {
        end--;
    }
    return str_substring(s, start, end + 1);
}

str* str_substring(str* s, size_t start, size_t end) {
    if (start >= end) {
        return str("");
    }
    str* result = str("");
    result->data = (char *)realloc(result->data, end - start + 1);
    strncpy(result->data, s->data + start, end - start);
    result->data[end - start] = '\0';
    result->length = end - start;
    return result;
}


str* str_replace(str* s, str* old, str* new) {
    return str_replace_cstr(s, old->data, new->data);
}

str* str_replace_cstr(str* s, const char* old, const char* new) {
    str* result = str("");
    char* p = strstr(s->data, old);
    if (p == NULL) {
        return s;
    }
    while (p != NULL) {
        str_append(result, str_substring(s, 0, p - s->data));
        str_append_cstr(result, new);
        s = str_substring(s, p - s->data + strlen(old), s->length);
        p = strstr(s->data, old);
    }
    str_append(result, s);
    return result;
}

str* str_to_upper(str* s) {
    str* result = str("");
    for (size_t i = 0; i < s->length; i++) {
        if (s->data[i] >= 'a' && s->data[i] <= 'z') {
            str_append_cstr(result, (char[]){s->data[i] - 'a' + 'A', '\0'});
        } else {
            str_append_cstr(result, (char[]){s->data[i], '\0'});
        }
    }
    return result;
}

str* str_to_lower(str* s) {
    str* result = str("");
    for (size_t i = 0; i < s->length; i++) {
        if (s->data[i] >= 'A' && s->data[i] <= 'Z') {
            str_append_cstr(result, (char[]){s->data[i] - 'A' + 'a', '\0'});
        } else {
            str_append_cstr(result, (char[]){s->data[i], '\0'});
        }
    }
    return result;
}

char* str_to_cstr(str* s) {
    return s->data;
}

