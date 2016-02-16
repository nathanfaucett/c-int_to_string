#ifndef __INT_TO_STRING_LIB_H__
#define __INT_TO_STRING_LIB_H__


#define INT_TO_STRING_DIGITS 19


#define INT_TO_STRING_HEADER(TYPE) \
    char* TYPE##_to_string(TYPE value);

#define UINT_TO_STRING_HEADER(TYPE) \
    char* TYPE##_to_string(TYPE value);


#define INT_TO_STRING_SRC(TYPE) \
    char* TYPE##_to_string(TYPE value) {\
        static char buffer[INT_TO_STRING_DIGITS + 2];\
        char* ascii = buffer + INT_TO_STRING_DIGITS + 1;\
        if (value >= 0) {\
            do {\
                *--ascii = '0' + (value % 10);\
                value /= 10;\
            } while (value != 0);\
        } else {\
            do {\
                *--ascii = '0' - (value % 10);\
                value /= 10;\
            } while (value != 0);\
            *--ascii = '-';\
        }\
        return ascii;\
    }\

#define UINT_TO_STRING_SRC(TYPE) \
    char* TYPE##_to_string(TYPE value) {\
        static char buffer[INT_TO_STRING_DIGITS + 2];\
        char* ascii = buffer + INT_TO_STRING_DIGITS + 1;\
        do {\
            *--ascii = '0' + (value % 10);\
            value /= 10;\
        } while (value != 0);\
        return ascii;\
    }\


INT_TO_STRING_HEADER(intsize);
UINT_TO_STRING_HEADER(uintsize);


#endif
