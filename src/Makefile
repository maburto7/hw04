# place makefile contents here

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

# Output executable name
TARGET = hw04

# Source files
SRC = src/main.cpp src/artist.cpp src/artistList.cpp src/parse_csv.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Rule to build the target
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# Rule to build object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and the target executable
clean:
	rm -f $(OBJ) $(TARGET)

# Phony targets
.PHONY: clean
