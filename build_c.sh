COMPILER=gcc
FLAGS="-Wall -Wextra -Wformat=2"
OUTPUT=main

$COMPILER -o $OUTPUT $FLAGS $1
