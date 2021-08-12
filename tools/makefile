CXX= g++
CXXFLAGS= -Wall -W -Werror -MMD -O2 -g  #-std=c++NO
#LIBS

OBJS= sockUtils.o

SRCS:= $(OBJS: .o=.cc)

DEPS:= $(OBJS:.o=.d)

TARGET= sockUtils

.PHONY: all clean

all: $(TARGET)

clean:
		rm -f $(TARGET) $(OBJS) $(DEPS)


$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^



-include $(DEPS)



######comment line#####
#$(OBJS): $(SRCS)
#$(OBJS): %.o: %.cc
#	$(COMPILE.cc) -o $@ $<

#OBJS := $(SRCS:.cc=.o)
#DEPS := $(OBJS:.o=.d)

