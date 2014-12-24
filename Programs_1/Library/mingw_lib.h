#ifndef MINGW_LIB_H__
#define MINGW_LIB_H__

struct STRUCT_DLL {
   int  count_int;
   int* ints;
};

int func_dll(
    int                an_int,
    char*              string_filled_in_dll,
    struct STRUCT_DLL* struct_dll
);

#endif
