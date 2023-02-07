TARGETS = autograder

#ARCH = -m32
#CXXBASE = clang++
CXXBASE = g++
CXX = $(CXXBASE) $(ARCH) -std=c++17
CC = $(CXX)
CXXFLAGS = -ggdb -O -Wall -Werror

OBJS = autograder.o

# OBJS = stack_init.o stack_switch.o sync.o test.o thread.o timer.o
# HEADERS = stack.hh thread.hh timer.hh


all: $(TARGETS)

$(OBJS): $(HEADERS)


# test_submission: test_submission.cc
# 	$(CXX) -o $@ $^

#studentA_submission: studentA_submission.cc
#	$(CXX) -o $@ $^

autograder: autograder.cc
	$(CXX) -o $@ $^

#RunMain: $(OBJS) $(LIB)
#	$(CXX) -o $@ $(OBJS)

#PointerPlayground: $(OBJS) $(LIB)
#	$(CXX) -o $@ $(OBJS)


clean:
	rm -f $(TARGETS) $(OBJS) *.s *~ .*~

.SUFFIXES: .cc

.PHONY: all clean
