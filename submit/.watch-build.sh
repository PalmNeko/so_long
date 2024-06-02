

function run_command() {
	clear
	make -s && echo 'success building and output ./so_long'
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
