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
LDFLAGS      := -shared -Wl -L../OauthHelper -L/usr/lib/qt4/lib
LIBS         := -lOauthHelper -lQtXml -lQtCore -lQtNetwork
LDFLAGS      := $(LDFLAGS) $(LIBS)
TARGET        = libSinaApiProvider.so

##

OBJECTS       = ./SinaApi.o \
		./SinaApiProvider.o \
		./SinaParam.o \
		./parameter/count.o \
		./parameter/source.o \
		./parameter/page.o \
		./api/Statuses/friends_timeline.o \
        ./api/Statuses/SinaStatus.o \
		./api/Users/Show.o

all: $(TARGET)

.cpp.o:
	$(CXX) -c $(CXXFLAGS) -o "$@" "$<"

$(TARGET):  $(OBJECTS)
	rm -rf $(TARGET)
	$(LINK) $(LDFLAGS) -o $(TARGET) $(OBJECTS)

clean:
	rm -rf $(OBJECTS) $(TARGET)