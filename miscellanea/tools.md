# Useful tools & utilities

Here is a list of useful tools:

## Terminal Tools

### Standard Tools for Terminal

- tldr: summarising man page to practical use cases. [github](https://github.com/tldr-pages/tldr)
- rsync: fast, versatile, remote and local file copying utility.
    - Useful Options:
        - `-a` archive mode. Preserve ownership, permission, etc
        - `-v`: `--verbose`: Give verbose info
        - `-r`: copy recursively
        - `-z` : compress file during transfer
        - `-e`: specify remote shell to use
        - `--progress`: show progress during transfer
        - `--delete`: delete file that do not exist in source
        - `--dry-run`: perform tryout run without leaving changes
        - `--backup`: backup files before overwriting them
    - Copy local file to server through many jump servers: `rsync -av -e 'ssh -J user@jump_server_1,user@jumpserver_2' path_to_source_file user@destination_server:Path_of_Destination` 
- lm-sensors: provides tools and drivers for monitoring temperatures, voltage, and fans
    - Usage
        - Configure the sensors with `sudo sensors-detect`
        - Run sensors with `sensors`
- aria2: ultrafast download utility for http, ftp, sftp, torrent, etc.
    - usage is simple: `aria2c http://example.org/mylinux.torrent`, `aria2c http://example.org/mylinux.is`

### Outlandish Ones

- etherwake: (ether-wake on RHEL), start up a machine remotely

### Fancy Ones - Terminal 

- ncdu: ncurse disk usage


