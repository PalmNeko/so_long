
FILES=$(find . \( -name "*.h" -o -name "*.c" \) -not -path "*libft*" -not -path "*minilibx*" )

for file in ${FILES}; do
    RESULT="$(norminette $file | grep -v "OK")";
    if [ -n "$RESULT" ] ; then
        echo "$RESULT"
        break 
    fi
done