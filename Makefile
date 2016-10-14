CC = g++
FLAGS  = -Wall
CC_FLAGS = -std=c++11
LD_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf

SRCS := $(wildcard src/**.cpp)
OBJS := $(addprefix obj/,$(notdir $(SRCS:.cpp=.o)))

VERSION := $(shell git describe --abbrev=4 --tags)
VERSION_IN = src/version.h.in
VERSION_H = src/version.h
VERSION_CMD := sed -e "s/@VERSION@/$(VERSION)/" $(VERSION_IN)

EXE=bin/lue.out

all: $(EXE)

$(EXE): $(OBJS)
	@mkdir -p bin
	$(CC) $^ $(FLAGS) $(LD_FLAGS) -o $@

obj:
	@mkdir -p obj

obj/%.o: src/%.cpp | obj version
	$(CC) $< $(FLAGS) $(CC_FLAGS) -c -o $@

run: $(EXE)
	./$(EXE)

version:
	@$(VERSION_CMD) | cmp -s - $(VERSION_H) || \
		($(VERSION_CMD) > $(VERSION_H) ; echo "version updated to "$(VERSION))

clean:
	@rm -rf bin obj
