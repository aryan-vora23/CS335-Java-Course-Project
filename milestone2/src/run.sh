gcc -c Assembly_$1.s -o Assembly.o
gcc Assembly.o -o Assembly
./Assembly