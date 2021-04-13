#!/bin/bash

list=(2);
#echo 2
for ((i=3; i<=${1:-999999999999999999}; i+=2)); do
    is_prime=1;
    for j in ${list[@]}; do
	if [[ $(($j**2)) -le $i ]]; then
	    if [[ $(($i%$j)) == 0 ]]; then
		is_prime=0;
		break;
	    fi
	else
	    break;
	fi
    done
    if [[ $is_prime == 1 ]]; then
	list=(${list[@]} $i)
#	echo $i
    fi
done
