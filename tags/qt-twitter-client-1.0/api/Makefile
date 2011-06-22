#############################################################################
#
# Makefile for building: libSinaApiProvider.so
#
#############################################################################


CXX           = $(PREFIX)g++
LINK          = $(PREFIX)g++
CFLAGS       := -pipe -g -Wall -W -D_REENTRANT -fPIC
INCLUDES     := $(INCLUDES) -I../include 
CXXFLAGS     := $(CXXFLAGS) $(INCLUDES)
LDFLAGS      := $(LDFLAGS) -shared -Wl
LIBS         := -lQtXml -lQtCore
LDFLAGS      := $(LDFLAGS) $(LIBS)
TARGET        = libApiProvider.so

##

OBJECTS       = ./Status.o \
                ./Comment.o \
                ./User.o \
                ./ApiProvider.o

all: $(TARGET)

.cpp.o:
	$(CXX) -c $(CXXFLAGS) -o "$@" "$<"

$(TARGET):  $(OBJECTS)
	$(LINK) $(LDFLAGS) -o $(TARGET) $(OBJECTS)

clean:
	rm -rf $(OBJECTS) $(TARGET)
