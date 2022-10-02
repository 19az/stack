CC = g++
CFLAGS =
include ../debugflags

EXE = stack
SOURCES = main.cpp
INCLUDES_DIR = inc
include $(INCLUDES_DIR)/hash/Makefile

OBJECTS = $(SOURCES:.cpp=.o)

all: $(EXE)

$(EXE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
 
.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(EXE) $(OBJECTS)

