# Variables used for the implicit rules
CXX = g++
CXXFLAGS = -Wall -std=c++11 -g
#LDFLAGS = -lm

OBJECTS = test_vector_list.o Vector3D.o
DEPS = Node.h LinkedList.h Vector3D.h

# Basic rule to compile the program
vectors: $(OBJECTS)
	$(CXX) $^ -o $@ $(CXXFLAGS) $(LDFLAGS)

# Basic rule to compile the program
test: test_list.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(LDFLAGS)

%.o: %.cpp $(DEPS)
	$(CXX) -o $@ $< $(CXXFLAGS) -c

clean:
	-rm -f test vectors *.o

.PHONY: clean
