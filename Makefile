# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -g

# Include directories
INCLUDES = -I/mnt/data

# SFML Libraries
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Source files
SOURCES = node.cpp tree.cpp Demo.cpp test.cpp
OBJECTS = $(SOURCES:.cpp=.o)

# Executables
DEMO_EXEC = demo
TEST_EXEC = tests

# doctest
DOCTEST_INCLUDE = -I/mnt/data/doctest.h

# Targets
all: $(DEMO_EXEC) $(TEST_EXEC)

$(DEMO_EXEC): node.o tree.o Demo.o
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@ $(SFML_LIBS)

$(TEST_EXEC): node.o tree.o test.o
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@ $(DOCTEST_INCLUDE)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJECTS) $(DEMO_EXEC) $(TEST_EXEC)

# Phony targets
.PHONY: all clean
