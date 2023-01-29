# Shell Scripting Language

To create a simple shell script:
1) create a file ends in `.sh`
2) begin the file with the shibang: `#! /bin/shell`. (Somehow, this first line of shell is caleed 'shibang')
3) append the shell script
4) give the file executable permission by `chmod +x <filename.sh>`
5) run the file by typing its path. (or invoke `bash before it`)

## Useful shortcuts

- `Ctrl + a`: move cursor to the beginning of the line
- `Ctrl + e`: move cursor to the end of the line
- `Ctrl + u`: delete all characters before the cursor
- `Ctrl + k`: delete all characters after the cursor
- `Ctrl + w`: delete the word before the cursor
- `Ctrl + y`: paste the deleted characters
- `Ctrl + r`: search the history
- `Ctrl + l`: clear the screen
- `Ctrl + c`: terminate the current command
- `Ctrl + d`: exit the current Shell
- `Ctrl + z`: suspend the current command 
- `Ctrl + s`: stop the output to the screen
- `Ctrl + q`: allow the output to the screen
- `Ctrl + x + e`: edit the current command with the default editor
- `Ctrl + x + r`: recall and edit the previous command
- `Ctrl + x + u`: undo the last change
- `Tab`: auto-complete the command or filename
- `!!`: repeat the last command
