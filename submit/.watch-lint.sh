

function run_command() {
	clear
	echo 'lint watching ...'
	make lint
}

run_command
while true; do
	bash .wait_update.sh "$1"
	if [ $? -ne 0 ]; then 
		break
	fi
	run_command
	sleep 1;
done
