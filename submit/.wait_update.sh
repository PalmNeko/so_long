
PRE_RESULT="$(echo -n "$1 -exec stat -c=%Y {} \\;" | xargs find . -type f)"
while true; do
    NOW_RESULT="$(echo -n "$1 -exec stat -c=%Y {} \\;" | xargs find . -type f)"
    if [ "$PRE_RESULT" != "$NOW_RESULT" ]; then
        exit 1
    fi
    PRE_RESULT="$NOW_RESULT"
    sleep 1
done
