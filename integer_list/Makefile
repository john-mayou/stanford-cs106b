# Compiler and flags
CXX = clang++
CXXFLAGS = -std=c++20 -I/opt/homebrew/include

# Target executable
TARGET = main.exe

# Source files
SRC = $(wildcard *.cpp)

# Default rule: Build and run main executable
all: $(TARGET)
	./$(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Clean up build files
clean: rm -f $(TARGET)