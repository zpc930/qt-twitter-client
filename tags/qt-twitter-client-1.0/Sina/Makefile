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
LDFLAGS      := $(LDFLAGS) -shared -Wl -L../OauthHelper 
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
        ./api/Statuses/update_status.o \
        ./api/Statuses/SinaStatus.o \
        ./api/Statuses/user_timeline.o \
        ./api/Statuses/mentions.o \
        ./api/Comments/comments.o \
        ./api/Comments/comments_timeline.o \
        ./api/Comments/SinaComment.o \
        ./api/Comments/updateComment.o \
        ./api/Users/SinaUser.o \
		./api/Users/Show.o \
		./api/Users/HotUser.o \
		./api/Users/SuggestionsUser.o

all: $(TARGET)

.cpp.o:
	$(CXX) -c $(CXXFLAGS) -o "$@" "$<"

$(TARGET):  $(OBJECTS)
	rm -rf $(TARGET)
	$(LINK) $(LDFLAGS) -o $(TARGET) $(OBJECTS)

clean:
	rm -rf $(OBJECTS) $(TARGET)
