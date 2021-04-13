#!/bin/bash

# test language
# format test [executable]
function test() {
    for i in {2..6}; do
	out=$((time $1 $((10**$i))) 2>&1 | tr '\n' ',' | tr '\t' ',')
	echo $1 $((10**$i)) $out
    done
}

# i needs to draw from a list of executables
for i in "$@"; do
    test "$i"
done
