#############################################################################
#
# Makefile for building: libOauthHelper.so
#
#############################################################################

CXX           = g++
LINK          = g++
CFLAGS       := -pipe -g -Wall -W -D_REENTRANT -fPIC
INCLUDES     := -I../include -I$(QTPATH)/include
CXXFLAGS     := $(CXXFLAGS) $(INCLUDES)
LDFLAGS      := -shared
LIBS         := -loauth
LDFLAGS      := $(LDFLAGS) $(LIBS)
TARGET        = libOauthHelper.so

##

OBJECTS       = ./OauthHelper.o \

all: $(TARGET)

.cpp.o:
	$(CXX) -c $(CXXFLAGS) -o "$@" "$<"

$(TARGET):  $(OBJECTS)
	rm -rf $(TARGET)
	$(LINK) $(LDFLAGS) -o $(TARGET) $(OBJECTS)

clean:
	rm -rf $(OBJECTS) $(TARGET)
