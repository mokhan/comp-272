CC=gcc

test : main
	cgreen-runner -c main

ci : main
	mkdir -p junit
	cgreen-runner -c --xml=junit/ main

run : main
	./main

main : main.o words_test.o words.o priority_queue.o priority_queue_test.o
	$(CC) main.o words_test.o words.o priority_queue.o priority_queue_test.o -lcgreen -o main

main.o : main.c
	$(CC) -c main.c

words.o : words.c
	$(CC) -c words.c

words_test.o : words_test.c
	$(CC) -c words_test.c

priority_queue.o : assignments/01/priority_queue.c
	$(CC) -c assignments/01/priority_queue.c

priority_queue_test.o : assignments/01/priority_queue_test.c
	$(CC) -c assignments/01/priority_queue_test.c

clean:
	rm main *.o
