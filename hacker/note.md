# Hackers Guide

## Traverse the Source code

When presented with large code base, use grep and find to navigate it. 

Grep is used to find pattern in a file
- `grep -FHrni <fix-word>` searches for fixed word, ignoring case, recursively, following symbolic links, and showing line numbers.
- `grep -w <fix-word> <file>` searches for fixed word in the <file>
- `grep -Hr -e <regex>` uses regex pattern

Find helps to find file, directory, with certain names.
- `find -name <pattern>` find files whose name fits glob <pattern>
- `find -iname <pattern>` find files whose name fits glob <pattern>, ignoring cases.
- `find -regex <regex-pattern>` find files whose name fits <regex-pattern>
- `find -type d`: only shows directories.

## Binary

A hacker is by name investigator of binaries. Here are some tools for analysing binary files.

- `file`
- `ldd`
- `ltrace`
- `strace`
- `objdump`
- `nm`
- `readelf`
- `strings`
- `hexdump -C`
- `xxd` 
- `hexyl`

## GDB
