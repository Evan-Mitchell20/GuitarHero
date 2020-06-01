CC = g++
CFLAGS= -std=c++11 -c -Wall 
LDFLAGS=
SOURCES= RingBuffer.hpp RingBuffer.cpp GuitarHero.cpp GuitarString.cpp GuitarString.hpp
OBJECTS=$(SOURCES:.cpp=.o)
LIBS= -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system -lboost_unit_test_framework
EXECUTABLE = GuitarHero

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(LIBS)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBS)

clean:
	rm GuitarHero RingBuffer.cpp~ RingBuffer.hpp~ RingBuffer.o GuitarHero.cpp~ GuitarHero.o ps5b-readme.txt~ GuitarString.o GuitarString.cpp~ GuitarString.hpp~ Makefile~


