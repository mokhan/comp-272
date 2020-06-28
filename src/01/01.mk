#test : build/main
	#cgreen-runner -c main

#main : main.o priority_queue_test.o stack_test.o swap_singly_linked_list_test.o swap_doubly_linked_list_test.o min_stack_test.o
	#$(CC) main.o priority_queue_test.o stack_test.o swap_singly_linked_list_test.o swap_doubly_linked_list_test.o min_stack_test.o -lcgreen -o main

#main.o : src/01/main.c
	#$(CC) -c main.c

all : build/priority_queue_test.o build/stack_test.o build/min_stack_test.o build/swap_singly_linked_list_test.o build/swap_doubly_linked_list_test.o

build/priority_queue_test.o : src/01/priority_queue_test.c
	$(CC) -c src/01/priority_queue_test.c

build/stack_test.o : src/01/stack_test.c
	$(CC) -c src/01/stack_test.c

build/min_stack_test.o : src/01/min_stack_test.c
	$(CC) -c src/01/min_stack_test.c

build/swap_singly_linked_list_test.o : src/01/swap_singly_linked_list_test.c
	$(CC) -c src/01/swap_singly_linked_list_test.c

build/swap_doubly_linked_list_test.o : src/01/swap_doubly_linked_list_test.c
	$(CC) -c src/01/swap_doubly_linked_list_test.c
