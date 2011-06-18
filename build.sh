#!/bin/bash

# prepare LD_LIBRARY_PATH
if [ -z $OLD_LD_LIBRARY_PATH ]
then 
    export OLD_LD_LIBRARY_PATH=$LD_LIBRARY_PATH 
fi

export LD_LIBRARY_PATH=$OLD_LD_LIBRARY_PATH:`pwd`/lib

# prepare QTPATH
if [ -z $QTPATH ] 
then 
	echo   "Please use export QTPATH=xxx" 
	exit 1
fi

echo "QTPATH : $QTPATH"

OBJ_DIRS=(HttpHelper OauthHelper Sina api ManagerFactory)
if [ $# -eq 0 ]
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
elif [ $1 = "clean" ]
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
