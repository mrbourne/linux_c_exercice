./bin/myls: ./tmp/myls.o
	gcc -o ./bin/myls ./tmp/myls.o
./tmp/myls.o: ./src/myls.c
	gcc -c ./src/myls.c -o ./tmp/myls.o
