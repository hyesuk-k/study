CC = g++
CXXFLAGS = -Wall -O2
OBJS = chap1.o

%.o : %.cpp %.h
		$(CC) $(CXXFLAGS) -c $<
main : $(OBJS)
		$(CC) $(CXXFLAGS) $(OBJS) -o main
	
.PHONY: clean
clean:
		rm -f $(OBJS) main

-include $(OBJS:.o=.d)