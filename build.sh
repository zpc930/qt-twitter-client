#!/bin/sh
OBJ_DIRS=(HttpHelper OauthHelper Sina api ManagerFactory)
if [ $# -eq 0 ]
then
    for dir in ${OBJ_DIRS[@]}
    do
        cd $dir; echo "entry $dir";
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
