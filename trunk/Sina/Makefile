#############################################################################
#
# Makefile for building: libSinaApiProvider.so
#
#############################################################################


CXX           = g++
LINK          = g++
CFLAGS       := -pipe -g -Wall -W -D_REENTRANT -fPIC
INCLUDES     := -I../include
CXXFLAGS     := $(CXXFLAGS) $(INCLUDES)
LDFLAGS      := -shared -Wl
LIBS         := -loauth 
LDFLAGS      := $(LDFLAGS) $(LIBS)
TARGET        = libApiProvider.so

##

OBJECTS       = ./SinaApi.o \
		./SinaApiProvider.o \
		./SinaParam.o \
		./parameter/count.o \
		./parameter/source.o \
		./parameter/page.o \
		./api/Statuses/friends_timeline.o \
		./api/Users/Show.o

all: $(TARGET)

.cpp.o:
	$(CXX) -c $(CXXFLAGS) -o "$@" "$<"

$(TARGET):  $(OBJECTS)
	rm -rf $(TARGET)
	$(LINK) $(LDFLAGS) -o $(TARGET) $(OBJECTS)

clean:
	rm -rf $(OBJECTS) $(TARGET)
