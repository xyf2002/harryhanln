# The terminal

## $PATH

When typing a command in terminal, the shell automatically searches all executable in the lists of directories included in the `$PATH`. 

To see directories included in the `$PATH`, use command `echo $PATH`. 

To added a new directories in `$PATH`, use the command 
`export PATH="/dir/to/includ3:$PATH"`.

To make the effect permanent, append the same command in the `~/.bashrc` file. 
