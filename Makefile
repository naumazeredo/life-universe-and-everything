CC=g++
LIBS=-lSDL2 -lSDL2_image -lSDL2_ttf
OPTS=-Wall -std=c++11

SRCS=src/main.cpp src/game.cpp src/texture.cpp src/texture_manager.cpp src/sprite.cpp
EXE=bin/lue.out

all: $(EXE)

$(EXE): $(SRCS)
	@mkdir -p bin
	$(CC) $^ $(OPTS) $(LIBS) -o $@

run: $(EXE)
	./$(EXE)

clean:
	@rm -r bin
