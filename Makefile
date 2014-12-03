CXX=g++
CXXFLAGS=-Wall -pedantic -ansi -g -std=c++0x
LDFLAGS= 
SOURCES=fraction.cpp util.cpp sample.cpp unit_tests.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=coursework

all:  $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

.cc:
	$(CXX) $(CXXFLAGS) $< -o $@

.cpp:
	$(CXX) $(CXXFLAGS) $< -o $@

.o:
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	-rm -f *.o $(EXECUTABLE)
	-rm -rf *.dSYM