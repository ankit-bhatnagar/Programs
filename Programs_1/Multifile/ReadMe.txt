In Makefile don't forget to link to libstdc++ as it gives linker error

i think no library is needed to add in case of mingw runtime are used 

How to use shared libstdc++

Compile with -D_GLIBCXX_DLL and add -lstdc++_s to your link flags to link against a DLL version of libstdc++

-s is used to strip all symbols from binary to minimize size