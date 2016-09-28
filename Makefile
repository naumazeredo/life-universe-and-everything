CC=g++
LIBS=-lSDL2 -lSDL2_image
OPTS=-Wall -std=c++11

SRCS=src/main.cpp src/game.cpp src/texture.cpp src/texture_manager.cpp
EXE=bin/lue.out

all: $(EXE)

$(EXE): $(SRCS)
	@mkdir -p bin
	$(CC) $^ $(OPTS) $(LIBS) -o $@

run: $(EXE)
	./$(EXE)

clean:
	@rm -r bin
