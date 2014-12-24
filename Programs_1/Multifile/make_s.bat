g++ -c fileB.cpp

g++ -c fileA.cpp

g++ -D_GLIBCXX_DLL fileB.o fileA.o -lstdc++_s -o Multifile_S

pause