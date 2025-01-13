# Load .env file
ifneq (,$(wildcard .env))
    include .env
    export
endif

# Compiler and flags
CXX = clang++
CXXFLAGS = -std=c++20 -I/opt/homebrew/include -I/opt/homebrew/Cellar/magic_enum/0.9.7/include/magic_enum/

# Target executable
TARGET = main.exe

# Source files
ifneq ($(strip $(FILE)),)
  SRC = chapter-$(CHAPTER)/$(FILE).cpp
else ifneq ($(strip $(DIR)),)
  SRC = $(wildcard chapter-$(CHAPTER)/$(DIR)/*.cpp)
else
  $(error "Specify either FILE or DIR, e.g., make FILE=3 CHAPTER=3 or make DIR=3 CHAPTER=3")
endif

# Default rule: Clear, build and run main executable
all:
	rm -f $(TARGET)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)
	./$(TARGET)