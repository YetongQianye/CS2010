#!/bin/bash
n=2
s=0
while [ $n -le 10 ]
do
	flag=1  #是素数
	i=2
	while [ $i -lt $n ]
	do
		r=`expr $n % $i`
		if [ $r -eq 0 ];then
			flag=0
			break
		fi
		i=`expr $i + 1`
	done
	if [ $flag -eq 1 ];then
		s=`expr $s + $n`
	fi
	n=`expr $n + 1`
done
echo $s


