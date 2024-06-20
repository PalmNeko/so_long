
norm_format () {
    NORM_OUTPUT="$1"
    FILE_NAME=$(echo "$NORM_OUTPUT" | head -n 1 | awk -F ':' '{print $1}')
    ERROR_LOG=$(echo "$NORM_OUTPUT" | tail -n +2)
    echo "$ERROR_LOG" | while read LINE; do
        ROWNO=$(echo "$LINE" | grep -oE '[[:digit:]]+' | sed -n 1p)
        COLNO=$(echo "$LINE" | grep -oE '[[:digit:]]+' | sed -n 2p)
        ERR_TYPE=$(echo "$LINE" | awk '{print $2}')
        ERR_MSG=$(echo "$LINE" | grep -oE '[[:alpha:]]([[:alpha:]]|[[:space:]])+$')
        echo "Error: $FILE_NAME:$ROWNO:$COLNO $ERR_TYPE: $ERR_MSG"
    done
}

FILES=$(find . \( -name "*.h" -o -name "*.c" \) -not -path "*libft*" -not -path "*minilibx*" -not -path "*cident*")

for file in ${FILES}; do
    RESULT="$(norminette $file | grep -v "OK")";
    if [ -n "$RESULT" ] ; then
        norm_format "$RESULT"
        break
    fi
done
