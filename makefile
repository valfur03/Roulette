CC=g++
CFLAGS=-Wall -O
LDFLAGS=
EXEC=run
SRC=$(wildcard sources/*.cpp)
OBJ=$(SRC: .cpp=.o)

all: $(EXEC)
	./$(EXEC)

run: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

main.o: includes/Game.h

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f *.o core

mrproper: clean
	rm -f ./$(EXEC)

