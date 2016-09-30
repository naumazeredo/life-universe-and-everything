CC = g++
FLAGS  = -Wall
CC_FLAGS = -std=c++11
LD_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf

SRCS := $(wildcard src/**.cpp)
OBJS := $(addprefix obj/,$(notdir $(SRCS:.cpp=.o)))

EXE=bin/lue.out

all: $(EXE)

$(EXE): $(OBJS)
	@mkdir -p bin
	$(CC) $^ $(FLAGS) $(LD_FLAGS) -o $@

obj:
	@mkdir -p obj

obj/%.o: src/%.cpp | obj
	$(CC) $< $(FLAGS) $(CC_FLAGS) -c -o $@

run: $(EXE)
	./$(EXE)

clean:
	@rm -r bin obj
