CXX = g++
CXXFLAGS = -std=c++20 -fsanitize=address -I ../include -g -Wall -Wextra

SRC_FILES = main.cpp artistList.cpp artist.cpp parse_csv.cpp

OBJ_FILES = main.o artistList.o artist.o parse_csv.o

TARGET = hw04

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ_FILES)

lib/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o lib/$@

clean:
	rm -f lib/*.o $(TARGET)
