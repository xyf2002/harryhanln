# Working with Terminal

## What is Shell (Terminal)? A Breif History

## Quick Start

### Keyboard Shortcuts 

#### Navigation

-`Ctrl + A`: move to the beginning of the Line
-`Ctrl + E`: move to the end of the Line 
-`Ctrl + <Arrow Key>`: move to previous or next word


#### Copy and Paste

-`Ctrl + U`: delete from cursor to the beginning of the Line 
-`Ctrl + K`: delete from cursor to the end of the Line 
-`Ctrl + W`: delete word before the cursor
-`Alt + D`: delete word after the cursor
-`Ctrl + Y`: paste word or text that was cut 

#### Histroy Command and Search

-`Ctrl + R`: search the history backwards. Use arrow keys edit the command
-`Ctrl + p`: previous command in history 
-`Ctrl + n`: next command in history
-`history`: show history of commands
-`!<number>`: execute the command with the number in history
-`!!`: execute the most recent command
-`!<string>`: execute the most recent command that starts with `<string>`
-`!<string>:p`: print the most recent command that starts with `<string>`

#### Others

-`Ctrl + C`: kill whatever you are running 
-`Ctrl + D`: exit the current Shell 
-`Ctrl + Z`: put whatever you are running into a suspended background process. fg restores it. 
-`Ctrl + L`: clear the Screen, similar to the clear command 


## A reference of commonly used utility

- `|`: the pipe
- `>, >>`: redirect to file
- `uniq`: only output unique line

## Reference

- [GNU/Linux Command Line Tool Summary](https://tldp.org/LDP/GNU-Linux-Tools-Summary/html/index.html)
- [Effective Shell](https://effective-shell.com/)
