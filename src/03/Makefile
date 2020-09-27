#!/usr/bin/make -f
SHELL=/bin/sh

CC=clang
TEST_LIBS = -lcgreen -lm

BUILDDIR := build
OBJS := $(addprefix $(BUILDDIR)/,avl_tree.o rb_tree.o sort.o graph.o matrix.o meldable_heap.o btree.o)
TEST_OBJS := $(addprefix $(BUILDDIR)/,avl_tree_test.o rb_tree_test.o sort_test.o graph_test.o matrix_test.o meldable_heap_test.o btree_test.o)

$(BUILDDIR)/%.o : %.c
	$(COMPILE.c) $(OUTPUT_OPTION) $<

.PHONY: all
all: $(OBJS) $(BUILDDIR)/main.o
	$(CC) $(OBJS) $(BUILDDIR)/main.o $(TEST_LIBS) -o $(BUILDDIR)/program

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
