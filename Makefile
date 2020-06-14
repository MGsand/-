all: bin/prog

bin/prog: build/main.o build/sort.o build/print.o build/word_splitting.o
	gcc -Wall -Werror build/main.o build/sort.o build/print.o build/word_splitting.o -o bin/prog -lm

build/sort.o: src/sort.c
	gcc -Wall -Werror -c src/sort.c -o build/sort.o

build/print.o: src/print.c
	gcc -Wall -Werror -c src/print.c -o build/print.o

build/main.o: src/main.c
	gcc -I -Wall -Werror -c src/main.c -o build/main.o

build/word_splitting.o: src/word_splitting.c
	gcc -Wall -Werror -c src/word_splitting.c -o build/word_splitting.o -lm

run:
	./bin/prog ./word.txt

.PHONY: clean all

clean:
	rm -rf build/*.o bin/prog sort.txt
