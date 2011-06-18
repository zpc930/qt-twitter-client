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
LDFLAGS      := -shared -Wl -L../OauthHelper -L$(QTPATH)/lib
LIBS         := -lQtXml -lQtCore -lQtNetwork
LDFLAGS      := $(LDFLAGS) $(LIBS)
TARGET        = libhttphelper.so

##

OBJECTS       = ./PostParameter.o \
                ./Response.o \
                ./BasicAuthorization.o

all: $(TARGET)

.cpp.o:
	$(CXX) -c $(CXXFLAGS) -o "$@" "$<"

$(TARGET):  $(OBJECTS)
	rm -rf $(TARGET)
	$(LINK) $(LDFLAGS) -o $(TARGET) $(OBJECTS)

clean:
	rm -rf $(OBJECTS) $(TARGET)
