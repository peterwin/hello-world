LINK    = @echo linking $@ && g++
GCC     = @echo compiling $@ && g++
GC      = @echo compiling $@ && gcc
AR      = @echo generating static library $@ && ar crv
FLAGS   = -g -DDEBUG -W -Wall -fPIC
GCCFLAGS =
DEFINES =
HEADER  = -I./
LIBS    =
LINKFLAGS =

#LIBS    += -lrt
#LIBS    += -pthread

OBJECT := bstree.o bstree_test.o

BIN_PATH = ./

TARGET = main

$(TARGET) : $(OBJECT)
	$(GC) $(FLAGS) $(LINKFLAGS) -o $@ $^ $(LIBS)

.c.o:
	$(GC) -c $(HEADER) $(FLAGS) -o $@ $<

install: $(TARGET)
	cp $(TARGET) $(BIN_PATH)

clean:
	rm -rf $(TARGET) *.o *.so *.a
