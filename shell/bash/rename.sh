#!/bin/bash

for file in $(find . -name '*.cpp' );
do mv -- "$file" "${file%.cpp}.cc"
done

