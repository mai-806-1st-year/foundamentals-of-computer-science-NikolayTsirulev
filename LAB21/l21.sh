#!/bin/bash

directory=$1
suffix=$2
output_file=$3
max_size=$4

find "$directory" -type f -name "*.$suffix" -size "-${max_size}c" -printf "%f %s\n" > "$output_file"
