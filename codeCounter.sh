#!/bin/sh
DIRS={Sina,include,HttpHelper,api,ManagerFactory,UI,OauthHelper}
find ./{Sina,include,HttpHelper,api,ManagerFactory,UI,OauthHelper} -regex '.*\.\(h\|cpp\)' -exec wc -l {} \;
sum=0
for count in `find ./{Sina,include,HttpHelper,api,ManagerFactory,UI,OauthHelper} -regex '.*\.\(h\|cpp\)' -exec wc -l {} \; | awk '{print $1}'`
do
    sum=$((sum+$count));
done;
echo ""
echo "代码总行数:$sum"
