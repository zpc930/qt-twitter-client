#############################################################################
#
# Makefile for building: TestCase :oauthtest
#
#############################################################################


CXX           = g++
LINK          = g++
CFLAGS       := -pipe -g -Wall -W -D_REENTRANT -fPIC
INCLUDES     := -I../../include -I$(QTPATH)/include
CXXFLAGS     := $(CXXFLAGS) $(INCLUDES)
LDFLAGS      := -Wl -L/usr/local/lib -L../../OauthHelper -L../../Sina -L$(QTPATH)/lib -L../../api -L../../HttpHelper
LIBS         := -loauth -lOauthHelper -lSinaApiProvider -lQtXml -lQtNetwork -lQtCore -lApiProvider -lhttphelper
LDFLAGS      := $(LDFLAGS) $(LIBS)
TARGET        = oauthtest

##

OBJECTS       = ./OauthTest.o \

all: $(TARGET)

.cpp.o:
	$(CXX) -c $(CXXFLAGS) -o "$@" "$<"

$(TARGET):  $(OBJECTS)
	rm -rf $(TARGET)
	$(LINK) $(LDFLAGS) -o $(TARGET) $(OBJECTS)

clean:
	rm -rf $(OBJECTS) $(TARGET)
