CXX=g++
CXXFLAGS= -Wall -pedantic -ansi -g -std=c++0x
LDFLAGS= 
OBJECTS = fraction.o util.o sample.o 
PROGS = sample_main samplet_main fraction_main unit_tests
MAINS = $(PROGS:=.o)
BUILD_DIR = out

all: $(PROGS)

test: $(PROGS:%=%.tst)

%_main.tst: $(PROGS) test_data/test_%_good.txt test_data/test_%_bad.txt
	./$*_main < test_data/test_$*_good.txt 2>&1 > test_$*_good.out
	./$*_main < test_data/test_$*_bad.txt 2>&1 > test_$*_bad.out

unit_tests.tst: $(PROGS)
	./unit_tests 2>&1 > unit_test.out

$(PROGS): % : %.o $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) $@.o -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

clean:
	-rm -f *.o $(PROGS) *.out
	-rm -rf *.dSYM