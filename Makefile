CC=gcc
OBJDIR := build
objects = build/*.o
OBJS := $(addprefix $(OBJDIR)/,priority_queue_test.o stack_test.o min_stack_test.o swap_singly_linked_list_test.o swap_doubly_linked_list_test.o)

include src/**/*.mk

#test : build/main
	#cgreen-runner -c main

#ci : build/main
	#mkdir -p junit
	#cgreen-runner -c --xml=build/junit/ main

#doc : doc/
	#doxygen Doxyfile

#build/main : $(objects)
	#$(CC) -o build/main $(CFLAGS) $(objects)
	#$(CC) main.o priority_queue_test.o stack_test.o swap_singly_linked_list_test.o swap_doubly_linked_list_test.o min_stack_test.o -lcgreen -o main

$(OBJDIR)/%.o : %.c
	$(COMPILE.c) $(OUTPUT_OPTION) $<

all: $(OBJS)

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	rm -fr build
