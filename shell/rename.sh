#!/bin/sh

files=$(find . -name "*keymapss.lua")
for file in $files; do
  tmp=$(echo $file | sed 's/keymapss/keymaps/g')
  mv $file $tmp
done

