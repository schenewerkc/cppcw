CXX=g++
CXXFLAGS=-Wall -pedantic -ansi -g -std=c++0x
LDFLAGS= 
SOURCES=fraction.cpp util.cpp sample.cpp
OBJECTS=$(SOURCES:.cpp=.o)
PROGS = sample_test sample_t_test fraction_test

all:  $(PROGS)

$(PROGS): $(OBJECTS)

	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

.cc:
	$(CXX) $(CXXFLAGS) $< -o $@

.cpp:
	$(CXX) $(CXXFLAGS) $< -o $@

.o:
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	-rm -f *.o $(PROGS)
	-rm -rf *.dSYM