#!/bin/sh
echo "Generating Dynamic Library..."
sleep 1
echo "Creating dbuild Directory..."
mkdir dbuild
echo "Generating libmystring.so ..."
sleep 0.5
gcc -Iinclude src/mystrcat.c src/mystrcmp.c src/mystrcpy.c src/mystrlen.c -c 
gcc -shared -o dbuild/libmystring.so mystrcat.o mystrcmp.o mystrcpy.o mystrlen.o 
echo "Generating libmyutils.so ..."
sleep 0.5
gcc -Iinclude src/factorial.c src/isPrime.c src/isPalindrome.c src/vsum.c -c 
gcc -shared -o dbuild/libmyutils.so factorial.o isPrime.o isPalindrome.o vsum.o 
echo "Generating libbitmask.so ..."
sleep 0.5
gcc -Iinclude src/query.c src/flip.c src/set.c src/reset.c -c 
gcc  -shared -o dbuild/libbitmask.so flip.o query.o set.o reset.o 
echo "Generating Object for Test"
gcc -Iinclude src/test.c src/unity.c -c
sleep 0.5
echo "Linking dynamic Library..."
gcc test.o unity.o -Ldbuild -lmystring -lmyutils -lbitmask -o dbuild/all.out 
sleep 0.5
LD_LIBRARY_PATH=dbuild ./dbuild/all.out
echo "Size of Dynamic Library"
stat dbuild/all.out



