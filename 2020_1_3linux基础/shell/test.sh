#########################################################################
# File Name: test.sh
# Author: HMW
# mail: xxx.xxx.com
# Created Time: Sat 04 Jan 2020 02:23:01 PM CST
#########################################################################
#!/bin/bash
echo "hello world"
rm 100.c
echo $?
DATE=`date`
echo $DATE

files=`ls -l`
echo $files

echo "------------------"
echo $0
echo $1
echo $2
echo "------------------"
echo $@
echo $*


