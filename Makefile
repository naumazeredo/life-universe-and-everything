CC=g++
LIBS=-lSDL2
OPTS=-Wall -std=c++11

SRCS=src/main.cpp src/game.cpp
EXE=bin/lue.out

all: $(EXE)

$(EXE): $(SRCS)
	@mkdir -p bin
	$(CC) $^ $(OPTS) $(LIBS) -o $@

run: $(EXE)
	./$(EXE)

clean:
	@rm -r bin
