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

main : main.o priority_queue_test.o stack_test.o swap_singly_linked_list_test.o swap_doubly_linked_list_test.o min_stack_test.o
	$(CC) main.o priority_queue_test.o stack_test.o swap_singly_linked_list_test.o swap_doubly_linked_list_test.o min_stack_test.o -lcgreen -o main

main.o : main.c
	$(CC) -c main.c

priority_queue_test.o : src/01/priority_queue_test.c
	$(CC) -c src/01/priority_queue_test.c

stack_test.o : src/01/stack_test.c
	$(CC) -c src/01/stack_test.c

min_stack_test.o : src/01/min_stack_test.c
	$(CC) -c src/01/min_stack_test.c

swap_singly_linked_list_test.o : src/01/swap_singly_linked_list_test.c
	$(CC) -c src/01/swap_singly_linked_list_test.c

swap_doubly_linked_list_test.o : src/01/swap_doubly_linked_list_test.c
	$(CC) -c src/01/swap_doubly_linked_list_test.c

clean:
	rm -f main *.o
	rm -fr doc
