all: bin/prog bin/test

bin/prog: build/src/main.o build/src/sort.o build/src/print.o build/src/word_splitting.o
	gcc -Wall -Werror build/src/main.o build/src/sort.o build/src/print.o build/src/word_splitting.o -o bin/prog -lm

build/src/sort.o: src/sort.c
	gcc -Wall -Werror -c src/sort.c -o build/src/sort.o

build/src/print.o: src/print.c
	gcc -Wall -Werror -c src/print.c -o build/src/print.o

build/src/main.o: src/main.c
	gcc -I -Wall -Werror -c src/main.c -o build/src/main.o

build/src/word_splitting.o: src/word_splitting.c
	gcc -Wall -Werror -c src/word_splitting.c -o build/src/word_splitting.o -lm

build/test/main.o: test/main.c
	gcc -I thirdparty -I src -Wall -Werror -c test/main.c -o build/test/main.o

build/test/test.o: test/test.c
	gcc -I thirdparty -I src -Wall -Werror -c test/test.c -o build/test/test.o

bin/test: build/test/test.o build/test/main.o
	gcc -Wall -Werror build/src/sort.o build/src/word_splitting.o build/test/test.o build/test/main.o -o bin/test -lm
	./bin/test

run:
	./bin/prog ./word.txt

run_test:
	./bin/test

.PHONY: clean all

clean:
	rm -rf build/src/*.o build/test/*.o bin/prog bin/test sort.txt
