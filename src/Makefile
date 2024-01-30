CC = g++

CFLAGS =  -c -Wall 

LDFLAGS = -lgtest -pthread
TESTLDFLAGS = -lgtest -lpthread

SRCS =  binary_parser.cpp main.cpp 
TESTSRCS = generate_data.cpp

OBJS = $(SRCS:.c=.o)

EXE = prog
TESTEXE = testProg

all: $(SRCS) $(EXE)

$(EXE): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

test:
	$(CC) $(TESTSRCS) $(TESTLDFLAGS) -o $(TESTEXE)

cleanTest:
	rm -rf $(TESTEXE)

clean:
	rm -rf $(EXE)