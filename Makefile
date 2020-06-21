CC=gcc

test : main
	cgreen-runner -c main

ci : main
	mkdir -p junit
	cgreen-runner -c --xml=junit/ main

doc : doc/
	doxygen Doxyfile

run : main
	./main

main : main.o words_test.o words.o priority_queue_test.o stack_test.o swap_linked_list_test.o
	$(CC) main.o words_test.o words.o priority_queue_test.o stack_test.o swap_linked_list_test.o -lcgreen -o main

main.o : main.c
	$(CC) -c main.c

words.o : words.c
	$(CC) -c words.c

words_test.o : words_test.c
	$(CC) -c words_test.c

priority_queue_test.o : assignments/01/priority_queue_test.c
	$(CC) -c assignments/01/priority_queue_test.c

stack_test.o : assignments/01/stack_test.c
	$(CC) -c assignments/01/stack_test.c

swap_linked_list_test.o : assignments/01/swap_linked_list_test.c
	$(CC) -c assignments/01/swap_linked_list_test.c

clean:
	rm -f main *.o
	rm -fr doc
