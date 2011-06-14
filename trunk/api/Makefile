#############################################################################
#
# Makefile for building: libSinaApiProvider.so
#
#############################################################################


CXX           = g++
LINK          = g++
CFLAGS       := -pipe -g -Wall -W -D_REENTRANT -fPIC
INCLUDES     := -I../include -I/usr/lib/qt4/include
CXXFLAGS     := $(CXXFLAGS) $(INCLUDES)
LDFLAGS      := -shared -Wl -L/usr/lib/qt4/lib
LIBS         := -lQtXml -lQtCore
LDFLAGS      := $(LDFLAGS) $(LIBS)
TARGET        = libApiProvider.so

##

OBJECTS       = ./Status.o \

all: $(TARGET)

.cpp.o:
	$(CXX) -c $(CXXFLAGS) -o "$@" "$<"

$(TARGET):  $(OBJECTS)
	rm -rf $(TARGET)
	$(LINK) $(LDFLAGS) -o $(TARGET) $(OBJECTS)

clean:
	rm -rf $(OBJECTS) $(TARGET)
