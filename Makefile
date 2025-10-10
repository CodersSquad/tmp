# Define the compiler and compiler flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -g

# Define the names for the executable, source files, and object files
TARGET := main
SOURCES := person.cpp utils.cpp main.cpp
OBJECTS := $(SOURCES:.cpp=.o)

# Default rule to build the executable
all: $(TARGET)

# Rule to link the object files into the final executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)

# Generic rule to compile .cpp files into .o files
# $@ is the target, $< is the first prerequisite
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rules for explicit header dependencies
# These rules tell make which object files depend on which header files.
main.o: main.cpp person.h utils.h
person.o: person.cpp person.h
utils.o: utils.cpp utils.h

# Rule to clean up generated files
.PHONY: clean
clean:
	rm -f $(OBJECTS) $(TARGET)
