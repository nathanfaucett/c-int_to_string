#include <stdio.h>
#include <stdlib.h>

#include "../lib.h"
#include "../lib.c"


int main(void) {
    char* str0 = uintsize_to_string(32);
    puts(str0);
    char* str1 = uintsize_to_string(0);
    puts(str1);
    char* str2 = intsize_to_string(-32);
    puts(str2);
    return 0;
}
