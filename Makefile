CC=gcc

test : main
	cgreen-runner -c main

ci : main
	mkdir -p junit
	cgreen-runner -c --xml=junit/ main

run : main
	./main

main : main.o words_test.o words.o
	$(CC) main.o words_test.o words.o -lcgreen -o main

main.o : main.c
	$(CC) -c main.c

words.o : words.c
	$(CC) -c words.c

words_test.o : words_test.c
	$(CC) -c words_test.c

clean:
	rm main *.o
