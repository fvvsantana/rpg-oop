#parameters:
CC=gcc
CXX=g++
RM=rm -f
CFLAGS=
CPPFLAGS=-g #-I include/
CXXFLAGS=
LDFLAGS=-g
LDLIBS=

#project files:
PNAME=rpg_cpp2
SRCS=$(wildcard src/*.cpp) $(wildcard src/*/*.cpp) 
HDRS=$(wildcard include/*.hpp) $(wildcard include/*/*.hpp)
MKFL=makefile
OBJS=$(subst src,obj,$(subst .cpp,.o,$(SRCS)))

#build:
all: $(PNAME) 

$(PNAME): $(OBJS) $(MKFL) $(HDRS)
	$(CXX) $(LDFLAGS) -o $(PNAME) $(OBJS) $(LDLIBS) 

obj/%.o: src/%.cpp $(HDRS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@ 

#run:
run:
	./$(PNAME)

depend: .depend

.depend: $(SRCS)
	$(RM) ./.depend
		$(CXX) $(CPPFLAGS) -MM $^>>./.depend;

clean:
	$(RM) $(OBJS) $(PNAME)

distclean: clean
	$(RM) *~ .depend

include .depend
