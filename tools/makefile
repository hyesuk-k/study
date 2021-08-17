CXX= g++
CXXFLAGS= -Wall -W -MMD -O2 -g  #-Werror #-std=c++NO
#LIBS

OBJS= ClientUtil.o Socket.o ClientMain.o
OBJS2= ServerUtil.o Socket.o ServerMain.o

SRCS:= $(OBJS: .o=.cc)

DEPS:= $(OBJS:.o=.d)
DEPS2:= $(OBJS2:.o=.d)

TARGET= ClientMain
TARGET2= ServerMain

.PHONY: all clean

all: $(TARGET) $(TARGET2)

clean:
		rm -f $(TARGET) $(OBJS) $(DEPS)
		rm -f $(TARGET2) $(OBJS2) $(DEPS2)


$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(TARGET2): $(OBJS2)
	$(CXX) $(CXXFLAGS) -o $@ $^

-include $(DEPS)
-include $(DEPS2)

######comment line#####
#$(OBJS): $(SRCS)
#$(OBJS): %.o: %.cc
#	$(COMPILE.cc) -o $@ $<

#OBJS := $(SRCS:.cc=.o)
#DEPS := $(OBJS:.o=.d)

