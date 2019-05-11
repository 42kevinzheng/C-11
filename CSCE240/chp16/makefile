CC = g++  # use g++ compiler

FLAGS = -std=c++11  # compile with C++ 11 standard
FLAGS += -Wall      # compile with all warnings
FLAGS += -g         # produce debugging information

FLAGS += -I inc     # add inc directory include path
FLAGS += -I src     # add src directory include path

LINK = $(CC) $(FLAGS) -o
COMPILE = $(CC) $(FLAGS) -c

bin/days_in_month: src/days_in_month.cc
	$(LINK) $@ $^

bin/search: src/search.cc bin/queue.o bin/stack.o bin/ppt.o
	$(LINK) $@ $^

bin/test_ppt: src/test_ppt.cc bin/ppt.o bin/stack.o bin/queue.o
	$(LINK) $@ $^

bin/test_stack: bin/test_stack.o
	$(LINK) $@ $^
bin/test_queue: bin/test_queue.o bin/queue.o
	$(LINK) $@ $^

bin/test_stack.o : src/test_stack.cc src/stack.cc inc/stack.h
	$(COMPILE) $< -o $@
bin/test_queue.o : src/test_queue.cc inc/queue.h
	$(COMPILE) $< -o $@

bin/queue.o : src/queue.cc inc/queue.h inc/ppt.h
	$(COMPILE) $< -o $@

clean:
	@rm -f bin/*
