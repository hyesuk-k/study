# usage					 		 
# make VAR=<fileName>
# make all -> not use
# make clean VAR=<fileName>
# make cleanall      				
############################# 
VAR= "test"

CXX= g++
CXXFLAGS= -Wall -W -Werror -MMD -O2 -g  #-std=c++NO
#LIBS

OBJS= $(VAR).o
SRCS:= $(OBJS: .o=.cc)
DEPS:= $(OBJS:.o=.d)

TARGET= $(VAR)

.PHONY: all clean cleanall

all: $(TARGET)

clean:
	rm -f $(TARGET) $(OBJS) $(DEPS)

cleanall:
	find . -type f -executable -delete
	rm -r *.o *.d 

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

-include $(DEPS)
