#!/usr/bin/make -f
SHELL=/bin/sh

CC=clang
CFLAGS=-std=c99
TEST_LIBS = -lcgreen

BUILDDIR := build
OBJS := $(addprefix $(BUILDDIR)/,btree.o)
TEST_OBJS := $(addprefix $(BUILDDIR)/,btree_test.o)

$(BUILDDIR)/%.o : %.c
	$(COMPILE.c) $(OUTPUT_OPTION) $<

.PHONY: all
all: $(OBJS) $(BUILDDIR)/main.o
	$(CC) $(OBJS) $(BUILDDIR)/main.o -o $(BUILDDIR)/program

.PHONY: test
test: $(OBJS) $(TEST_OBJS)
	$(CC) $(OBJS) $(TEST_OBJS) $(TEST_LIBS) -o $(BUILDDIR)/test

$(OBJS): | $(BUILDDIR)

$(TEST_OBJS): | $(BUILDDIR)

$(BUILDDIR):
	mkdir $(BUILDDIR)

.PHONY: clean
clean:
	rm -fr build

run : all
	./build/program

run_test : test
	cgreen-runner -c -v $(BUILDDIR)/test
