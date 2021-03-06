SHELL := /bin/bash
objects := $(shell find src -mindepth 2 -maxdepth 2 -type d)

run :
	for i in $(objects); do cd $$i && make clean run && cd -; done

clean :
	for i in $(objects); do cd $$i && make clean && cd -; done

test :
	for i in $(objects); do cd $$i && make clean run_test && cd -; done

fmt :
	clang-format -i src/**/**/*.c
	clang-format -i src/**/*.c
