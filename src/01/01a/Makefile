#!/usr/bin/make -f
SHELL=/bin/sh

CC=gcc
LIBS = -lcgreen

BUILDDIR := build
OBJS := $(addprefix $(BUILDDIR)/,priority_queue.o priority_queue_test.o)

$(BUILDDIR)/%.o : %.c
	$(COMPILE.c) $(OUTPUT_OPTION) $<

.PHONY: all
all: $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(BUILDDIR)/program

$(OBJS): | $(BUILDDIR)

$(BUILDDIR):
	mkdir $(BUILDDIR)

.PHONY: clean
clean:
	rm -fr build

test : all
	cgreen-runner -c -v $(BUILDDIR)/program
