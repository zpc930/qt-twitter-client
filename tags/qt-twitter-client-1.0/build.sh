#!/bin/bash

#
if [ $# = 0 ]
then
    echo "Usage: $0 <local|arm> [clean]"
    exit 1
elif [ $1 = "arm" ]
then
    export PREFIX="arm-linux-"
    export CROSS_PATH=`pwd`/cross-compile
    export CROSS_CFLAGS=-I$CROSS_PATH/include
    export CROSS_LDFLAGS=-L$CROSS_PATH/lib
    export CXXFLAGS=$CROSS_CFLAGS
    export LDFLAGS=$CROSS_LDFLAGS
elif [ $1 = "local" ]
then
    export PREFIX=""
else 
    echo "Usage: $0 <local|arm> [clean]"
    exit 1
fi

# prepare LD_LIBRARY_PATH
if [ -z $OLD_LD_LIBRARY_PATH ]
then 
    export OLD_LD_LIBRARY_PATH=$LD_LIBRARY_PATH 
fi

export LD_LIBRARY_PATH=$OLD_LD_LIBRARY_PATH:`pwd`/lib

# prepare QTPATH
if [ $1 = "local" ] 
then
  if [ -z $QTPATH ]
  then
	echo   "Please use export QTPATH=xxx" 
	exit 1
  fi
fi

if [ $1 = "arm" ]
then
  if [ -z $ARM_QTPATH ] 
  then
        echo   "Please use export ARM_QTPATH=xxx"
        exit 2
  fi
fi


if [ $1 = "arm" ]
then
    export QTPATH=$ARM_QTPATH
fi

export INCLUDES=-I$QTPATH/include
export LDFLAGS=`echo $LDFLAGS -L$QTPATH/lib`

echo "QTPATH : $QTPATH"
echo "INCLUDE: $INCLUDES"
echo "LDFLAGS: $LDFLAGS"

OBJ_DIRS=(HttpHelper OauthHelper Sina api ManagerFactory)
if [ $# -eq 1 ]
then
    for dir in ${OBJ_DIRS[@]}
    do
        cd $dir; 
	echo "####################";
	echo "";
	echo "entry $dir";
	echo "";
	echo "####################";
        make; 
        cp -v lib*.so* ../lib;
        cd -;
    done;
elif [ $2 = "clean" ]
then
    for dir in ${OBJ_DIRS[@]}
    do  
        cd $dir; echo "entry $dir";
        make clean;
        cd -;
    done;
else
    echo "invalid option $1";
fi
