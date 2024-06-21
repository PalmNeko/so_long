#!/bin/bash

if [ -z "$BASH_VERSION" ]; then
	echo 'please use bash'
	exit 1
fi

make -f tester.mk

# export IS_DEBUG=""
unset IS_DEBUG
export ERROR_COUNT_DOWN=""
TIMES=$(echo {1..375} | sed 's/ 2 / /g')
# 2 is mlx error
for i in $TIMES; do

	ERROR_COUNT_DOWN="$i"
	export ERROR_COUNT_DOWN
	RESULT="$(./so_long_test maps/sample.ber)"
	if [ $? -eq 0 ]; then
		echo "done: $i"
		exit 1
	else
		echo "error: $i"
		echo "$RESULT"
	fi
done
