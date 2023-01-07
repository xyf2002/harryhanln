# Notes on Shell (Terminal, bash)

## $PATH
When typing a command in terminal, the shell automatically searches all executable in the lists of directories included in the `$PATH`. 

To see directories included in the `$PATH`, use command `echo $PATH`. 

To added a new directories in `$PATH`, use the command 
`export PATH="$<HOME/dir>:$PATH"`. Replace `<HOME/dir>` with the actual direcotry. `HOME/` is the directory `home/<user>`. The effect of this commands expires after the current session is finished.

To make the effect permanent, append the same command in the `~/.bashrc` file. This requires `sudo` access.
