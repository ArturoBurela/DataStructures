# Makefile to compile a program using SFML
# For more information on makefiles, read:
#   http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/

# Variables with the options for compilation
CXX = g++
CXXFLAGS = -std=c++11 -g
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# List of the objects to compile
OBJECTS = test_viewer.o Viewer.o

# Variables with rule names
VIEWER = viewer

# Default rule
all: $(VIEWER)

# Rule to compile object files
# Commented because it is the same as an explicit rule in Make
#   https://ftp.gnu.org/old-gnu/Manuals/make-3.79.1/html_chapter/make_10.html
#%.o: %.c
	#$(CXX) -c -o $@ $< $(CXXFLAGS)

# Rule to compile the program
$(VIEWER): $(OBJECTS)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)

clean:
	-rm -f *.o

.PHONY: all clean
