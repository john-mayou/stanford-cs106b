# Compiler and flags
CXX = clang++
CXXFLAGS = -std=c++20 -I/opt/homebrew/include -I/opt/homebrew/Cellar/magic_enum/0.9.7/include/magic_enum/

# Target executable
TARGET = main.exe

# Source files
ifeq ($(origin FILE), command line)
  SRC = $(FILE)
else ifeq ($(origin DIR), command line)
  SRC = $(wildcard $(DIR)/*.cpp)
endif

# Default rule: Clear, build and run main executable
all:
	rm -f $(TARGET)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)
	./$(TARGET)