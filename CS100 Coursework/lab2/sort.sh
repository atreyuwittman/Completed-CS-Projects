#!/bin/sh
declare -a Array
declare -i temp
Array=(10 2 6 4 8)
echo ${Array[*]}
for i in 0 1 2 3 4
do
	for j in 0 1 2 3 4
	do
	if [ ${Array[$i]} -lt ${Array[$j]} ]; then
		temp=${Array[$i]}
		Array[$i]=${Array[$j]}
		Array[$j]=$temp
	fi
	done
done
echo ${Array[*]}
