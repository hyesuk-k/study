# usage					 		 
# make VAR=<fileName>
# make all -> not use
# make clean VAR=<fileName>
# make cleanall      				
############################# 
VAR= "test"

CXX= g++
CXXFLAGS= -Wall -W  -MMD -O2 -g
#CXXFLAGS= -Wall -W -Werror -MMD -O2 -g
#CXXFLAGS= -Wall -W -MMD -O2 -g #-Werror -MMD -O2 -g  #-std=c++NO
#LIBS

OBJS= $(VAR).o
SRCS:= $(OBJS: .o=.cc)
DEPS:= $(OBJS:.o=.d)

TARGET="test"


.PHONY: all clean cleanall

all: $(VAR)


clean:
	rm -f $(TARGET) $(OBJS) $(DEPS)
	rm -f *.o *.d

cleanall:
	find . -type f -executable -delete
	rm -r *.o *.d 

$(VAR): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^
	mv $(VAR) $(TARGET)

-include $(DEPS)
