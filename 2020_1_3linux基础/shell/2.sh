#########################################################################
# File Name: 2.sh
# Author: HMW
# mail: xxx.xxx.com
# Created Time: Sat 04 Jan 2020 03:01:30 PM CST
#########################################################################
#!/bin/bash
xxx=`./1`
read var1 var2 < 1.txt
echo "-------------"

echo $xxx
echo $var1 
echo $var2

echo "-------------"

ret=`expr 5 / 3`
echo $ret

i=6
ret=`expr $i + 5 + 3 \* 3`
echo $ret

str=
test = 
echo $?

echo "-------------"
[ -f $1 ]
echo $?


if [ -f $1 ]; then
	echo "regular file"
else
	echo "not regular file"
fi







