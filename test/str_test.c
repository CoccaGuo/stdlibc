#include "str.h"
#include "array.h"
#include <stdio.h>

int main()
{
    str* s = str(" Hello, world!\n |A|B|C|D|E  \n");
    printf("%s\n", str_to_cstr(s));
    str* s2 = str_trim(s);
    printf("%s\n", str_to_cstr(s2));

    str* s3 = str("|F|G|H|I_J_K_L");
    str* s31 = str_replace_cstr(s3, "_", "|");
    printf("%s\n", str_to_cstr(s31));

    array* str_list = str_split_cstr(s, "\n");
    str* s4 = array_at(str_list, 1);
    printf("%s\n", str_to_cstr(s4));

    str_append(s4, s31);
    printf("%s\n", str_to_cstr(s4));

    array* abc = str_split_cstr(s4, "|");
    for (size_t i = 0; i < array_size(abc); i++) {
        str* s = array_get(abc, i);
        printf("%s\n", str_to_cstr(s));
    }

    str_destroy(s);
    str_destroy(s2);
    str_destroy(s3);
    str_destroy(s31);
    str_destroy(s4);

    for (size_t i = 0; i < array_size(str_list); i++) {
        str_destroy(array_get(str_list, i));
    }

    array_destroy(str_list);

    for (size_t i = 0; i < array_size(abc); i++) {
        str_destroy(array_get(abc, i));
    }

    array_destroy(abc);

    return 0;
}