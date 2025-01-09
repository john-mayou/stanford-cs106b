# Compiler and flags
CXX = clang++
CXXFLAGS = -std=c++20 -I/opt/homebrew/include -I/opt/homebrew/Cellar/magic_enum/0.9.7/include/magic_enum

# Target executable
TARGET = main.exe

# Source files
SRC = $(wildcard *.cpp)

# Default rule: Build and run main executable
all: $(TARGET)
	./$(TARGET)

# Build only the main executable
build: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Clean up build files
clean:
	rm -f $(TARGET)