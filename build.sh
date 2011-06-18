#!/bin/bash

#prepare



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
