CXXFLAGS =	-O2 -g -Wall -Wextra -Werror -std=c++14 -fmessage-length=0

OBJS =		X.o Block.o

LIBS =

TARGET =	X

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)
	mkdir bin/
	mv $(TARGET) bin/

all:	$(TARGET)

clean:
	rm -rf $(OBJS) bin/
