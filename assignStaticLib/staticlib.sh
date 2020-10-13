#!/bin/sh
echo "Generating Static Library..."
sleep 1
if [ -d "/sbuild" ]; then
    echo "Removing sbuild Directory"
    rm -rf ssbuild 
    rm -rf *.o
else
    echo "Creating sbuild Directory..."
    mkdir sbuild
fi
echo "Generating libmystring.a ..."
sleep 0.5
gcc -Iinclude src/mystrcat.c src/mystrcmp.c src/mystrcpy.c src/mystrlen.c -c 
ar rc sbuild/libmystring.a mystrcat.o mystrcmp.o mystrcpy.o mystrlen.o 
echo "Generating libmyutils.a ..."
sleep 0.5
gcc -Iinclude src/factorial.c src/isPrime.c src/isPalindrome.c src/vsum.c -c 
ar rc sbuild/libmyutils.a factorial.o isPrime.o isPalindrome.o vsum.o 
echo "Generating libbitmask.a ..."
sleep 0.5
gcc -Iinclude src/query.c src/flip.c src/set.c src/reset.c -c 
ar rc sbuild/libbitmask.a flip.o query.o set.o reset.o 
echo "Generating Object for Test"
gcc -Iinclude src/test.c src/unity.c -c
sleep 0.5
echo "Linking Static Library ..."
gcc test.o unity.o -Lsbuild -lmystring -lmyutils -l bitmask -o sbuild/all.out -static
sleep 0.5
./sbuild/all.out
echo "Size of Static Library"
stat ./sbuild/all.out



