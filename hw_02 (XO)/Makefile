CXX = g++
CXXFLAGS = -O2 -Wall -Werror -std=c++11 -Iinclude
LDFLAGS = -lncurses

EXE = hw_02
SRCDIR = src
TESTDIR = test
BINDIR = obj
MAINS = $(BINDIR)/main.o
TESTEXE = test_board

OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(BINDIR)/%.o,$(wildcard $(SRCDIR)/*.cpp))
TESTOBJECTS = $(patsubst $(TESTDIR)/%.cpp,$(BINDIR)/%.o,$(wildcard $(TESTDIR)/*.cpp))

all: $(EXE)

$(TESTEXE): $(BINDIR) $(OBJECTS) $(TESTOBJECTS)
	$(CXX) $(TESTOBJECTS) $(filter-out $(MAINS), $(OBJECTS)) -o $(TESTEXE) $(LDFLAGS)
	
$(EXE): $(BINDIR) $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXE) $(LDFLAGS)
	
$(BINDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -MMD -o $@ $<

$(BINDIR)/%.o: $(TESTDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -MMD -o $@ $<

include $(wildcard $(BINDIR)/*.d)

$(BINDIR):
	mkdir -p $(BINDIR)

clean:
	rm -rf $(BINDIR) $(EXE) $(TESTEXE)

.PHONY: clean $(TESTEXE) all
