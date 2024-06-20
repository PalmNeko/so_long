#!/bin/bash

if [ "$SHELL" ~= "bash" ]; then
	echo 'please use bash'
	exit 1
fi

make -f tester.mk

export IS_DEBUG=""
export ERROR_COUNT_DOWN=""
for i in {1..300}; do

	ERROR_COUNT_DOWN="$i"
	export ERROR_COUNT_DOWN
	RESULT="$(./so_long_test maps/sample.ber)"
	if [ $? -eq 0 ]; then
		echo "done: $i"
	else
		echo "error: $i"
		echo "$RESULT"
		exit 1
	fi
done
