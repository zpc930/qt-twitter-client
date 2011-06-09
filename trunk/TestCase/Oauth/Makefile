#############################################################################
#
# Makefile for building: TestCase :oauthtest
#
#############################################################################


CXX           = g++
LINK          = g++
CFLAGS       := -pipe -g -Wall -W -D_REENTRANT -fPIC
INCLUDES     := -I../../include
CXXFLAGS     := $(CXXFLAGS) $(INCLUDES)
LDFLAGS      := -Wl -L../../OauthHelper -L../../Sina
LIBS         := -loauth -lOauthHelper -lSinaApiProvider
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
