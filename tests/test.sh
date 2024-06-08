
echo $1
FILE="$(echo "$1" | sed 's/\(.*\)\.c$/\1/g')"
make "$FILE" && "./$FILE"
