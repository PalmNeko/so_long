
PRE_RESULT="$(find . -type f -not -name "*.o" -not -name "*.d" -not -name "so_long" -exec stat -c=%Y {} \;)"
while true; do
    NOW_RESULT="$(find . -type f -not -name "*.o" -not -name "*.d" -not -name "so_long" -exec stat -c=%Y {} \;)"
    if [ "$PRE_RESULT" != "$NOW_RESULT" ]; then
        exit 1
    fi
    PRE_RESULT="$NOW_RESULT"
    sleep 1
done
