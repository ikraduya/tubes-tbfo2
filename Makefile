CC=gcc
SOURCES=src/main.c src/pdacalculator.c src/stackt.c include/pdacalculator.h include/stackt.h include/boolean.h
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=bin/main

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -f *.o src/*.o bin/*