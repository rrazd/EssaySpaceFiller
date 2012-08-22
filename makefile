PROGRAM = RandomWriter
OBJECTS = RandomWriter.o
DEPENDS = \
   RandomWriter.cpp \
   Makefile

ARCH = i386
CPPOPTIONS = -IStanfordCPPLib -arch $(ARCH) -fvisibility-inlines-hidden
LDOPTIONS = -LStanfordCPPLib -arch $(ARCH)
LIB = -lStanfordCPPLib

all: $(PROGRAM)

RandomWriter : $(OBJECTS)
	g++ -o $(PROGRAM) $(LDOPTIONS) $(OBJECTS) $(LIB)

RandomWriter.o : $(DEPENDS)
	@touch console.h
	g++ -c $(CPPOPTIONS) RandomWriter.cpp
	@rm console.h

clean:
	rm -f *.o *.a $(PROGRAM)
