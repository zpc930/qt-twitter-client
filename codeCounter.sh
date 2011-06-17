#!/bin/sh
find ./ -name "*.cpp" -exec wc -l {} \; #| awk 'BEGIN{total=0} {total+=$1} END{print $total}';
sum=0
for count in `find ./ -name "*.cpp" -exec wc -l {} \; | awk '{print $1}'`
do
    sum=$((sum+$count));
done;
echo ""
echo "代码总行数:$sum"
