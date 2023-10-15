# The Linus Kernel

## Compilation

### Install required packages

Listed on the [kernel.org](https://www.kernel.org/doc/html/latest/process/changes.html#required-packages) website.

### Check out to the proper tag

Check existing tag with `git tag -l`.

Create a branch based on tag and switch to it with: `git checkout -b [branchname] [tagname]`.

### Set build config file

Find the config file in `/boot`, `/proc/config.gz`, `/usr/src/kernel/`, or `/usr/src/linux/.config`.

Use command `zcat /proc/config.gz > .config` if the config file is an archive.

The config file shall be placed in the root directory of the kernel source tree and named `.config`.

The config file may be edited manually or by using `make menuconfig`. 

The config file shall be edited to suit the current kernel version by using `make oldconfig`. Press enter to accept the default value.

Note, it is recommand to have `CONFIG_EXT4_FS=y` in the config file.

### Compile the kernel (may take hours)

Use the command `make -j8` to compile the kernel. The number 8 is the number of threads to use. It is recommand to use the total number of the thread a cpu has.

Use `nproc` to get the number of threads a cpu has.

#### If the compilation failed

It is likely to be caused by the lack of dependencies. Install all require dependencies. Note certain distribution my have different dependencies than others. Try google `compile kernel fedora` (switch fedora for your dependencies)

__Do not `make` again!__ After failed compilation.

Backup the config file and use `make mrproper` to clean the source tree. 

#### Change the kernel version

If you want to change the name of the kernel, modify the `CONFIG_LOCALVERSION` (and probably `CONFIG_DEFAULT_HOSTNAME`) in the config file.

