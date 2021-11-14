COMPILER=gcc
FLAGS="-g -Wall -Wextra -Wformat=2 -IC"
OUTPUT=main

$COMPILER -o $OUTPUT $FLAGS $1
