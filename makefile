CC=g++
CFLAGS=-c -g -Wall -std=c++11 -Iinclude/
LDFLAGS=
LIBFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
SOURCES=src/main.cpp \
        src/control.cpp\
		src/drawableObject.cpp\
		src/hero.cpp\
		src/keyboard.cpp\
		src/enemy.cpp\
		src/util.cpp\
		src/gameStatusProvider.cpp\
		src/objectSpawner.cpp\
		src/character.cpp\
		
		
		
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=build/main

all: $(SOURCES) $(EXECUTABLE)
        
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o  $@ $(LIBFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@ $(LIBFLAGS)

clean:
	rm src/*.o $(EXECUTABLE)