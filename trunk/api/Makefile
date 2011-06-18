#############################################################################
#
# Makefile for building: libSinaApiProvider.so
#
#############################################################################


CXX           = g++
LINK          = g++
CFLAGS       := -pipe -g -Wall -W -D_REENTRANT -fPIC
INCLUDES     := -I../include -I$(QTPATH)/include
CXXFLAGS     := $(CXXFLAGS) $(INCLUDES)
LDFLAGS      := -shared -Wl -L$(QTPATH)/lib
LIBS         := -lQtXml -lQtCore
LDFLAGS      := $(LDFLAGS) $(LIBS)
TARGET        = libApiProvider.so

##

OBJECTS       = ./Status.o \
                ./Comment.o \
                ./User.o

all: $(TARGET)

.cpp.o:
	$(CXX) -c $(CXXFLAGS) -o "$@" "$<"

$(TARGET):  $(OBJECTS)
	$(LINK) $(LDFLAGS) -o $(TARGET) $(OBJECTS)

clean:
	rm -rf $(OBJECTS) $(TARGET)
