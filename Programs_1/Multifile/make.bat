gcc -c fileB.cpp

gcc -c fileA.cpp

gcc -s fileB.o fileA.o -o Multifile -lstdc++

pause