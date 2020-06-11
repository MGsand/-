all: bin/prog

bin/prog: build/main.o
	gcc -Wall -Werror build/main.o -o bin/prog -lm

build/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/main.o

run:
	./bin/prog ./word.txt

.PHONY: clean

clean:
	rm -rf build/*.o bin/prog sort.txt
