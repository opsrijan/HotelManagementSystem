# Define the compiler
CXX = g++

# Define compiler flags
CXXFLAGS = -O5 -pg -Wall -W

# Define the linker flags (if needed)
LDFLAGS =

# Define the target executable
TARGET = main

# Define the source files
SRCS = main.cpp

# Define the object files
OBJS = $(SRCS:.cpp=.o)

# Default rule to build the target executable
all: $(TARGET)

# Rule to link the object files into the target executable
$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $(OBJS)

# Rule to compile .cpp files into .o files
%.o: %.cpp func.h global.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to clean up generated files
clean:
	rm -f $(TARGET) $(OBJS)

# Phony targets
.PHONY: all clean
