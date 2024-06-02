
if [ $(uname) = "Darwin" ]; then
    CHK_COMMAND='ls -lT {}'
else
    CHK_COMMAND='stat -c=%Y {}'
fi

echo "quit: q, help: h"

PRE_RESULT="$(echo -n "$1 -exec $CHK_COMMAND \\;" | xargs find . -type f)"
NOW_RESULT="$(echo -n "$1 -exec $CHK_COMMAND \\;" | xargs find . -type f)"
while [ "$PRE_RESULT" = "$NOW_RESULT" ]; do
    CMD=""
    read -t 1 CMD;
    if [ "$CMD" = "h" ]; then
        echo "quit: q, help: h"
    elif [ "$CMD" = "q" ]; then
        exit 1
    fi
    NOW_RESULT="$(echo -n "$1 -exec $CHK_COMMAND \\;" | xargs find . -type f)"
done
exit 0
