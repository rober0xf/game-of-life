#!/bin/bash

CC=gcc
CFLAGS="-Wall -g $(sdl2-config --cflags)"
LDFLAGS="$(sdl2-config --libs)"
SRC_DIR="src"
OBJ_DIR="obj"
OUTPUT="game"

mkdir -p "$OBJ_DIR"

for src_file in "$SRC_DIR"/*.c; do
    obj_file="$OBJ_DIR/$(basename "$src_file" .c).o"
    echo "Compilando $src_file -> $obj_file"
    $CC $CFLAGS -c "$src_file" -o "$obj_file" || exit 1
done

$CC $CFLAGS -o "$OUTPUT" "$OBJ_DIR"/*.o $LDFLAGS || exit 1
