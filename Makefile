#!/usr/bin/make -f
SHELL=/bin/sh

CC=gcc
LIBS = -lcgreen

BUILDDIR := build
OBJS := $(addprefix $(BUILDDIR)/,priority_queue_test.o stack_test.o min_stack_test.o swap_singly_linked_list_test.o swap_doubly_linked_list_test.o main.o)

#doc : doc/
#doxygen Doxyfile

$(BUILDDIR)/%.o : src/01/%.c
	$(COMPILE.c) $(OUTPUT_OPTION) $<

test : all
	cgreen-runner -c $(BUILDDIR)/main

ci : all
	cgreen-runner -c --xml=$(BUILDDIR)/ $(BUILDDIR)/main

.PHONY: all
all: $(OBJS) $(BUILDDIR)/html
	$(CC) $(OBJS) $(LIBS) -o $(BUILDDIR)/main

$(OBJS): | $(BUILDDIR)

$(BUILDDIR):
	mkdir $(BUILDDIR)

$(BUILDDIR)/html :
	doxygen Doxyfile

.PHONY: clean
clean:
	rm -fr build
