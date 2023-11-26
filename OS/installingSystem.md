# Guide to Installing Computer Operation Systems

## Overview

For installing a operating system a bootable USB (with installation media) is usually required. The system can then be installed by 1) entering BIOS; 2) setting USB drive to be top of boot priority, then restart; 3)following installation instructions.

Labtops of different brands enters BIOS differently. 
Ususally the process is 1) shutdown the computer; 2) press and hold certain keys while the computer is rebooting.

For Asus computer, try F2.
For HP: try F10.
For others: try <ESC>, F1, F3, F5, F8; or consult documentations.
Apple computers can also enter BIOS to change boot order. However, installing any new systems onto macs usually leads to poor performance and compatibility. See notes on Apple products.

## Creating Bootable USB

### Ubuntu
To create the installation media:

1. Download the disk image file from the ubuntu official website
1. I have used belenaEtcher falsh OS images to USB drive, i.e. making the USB drive bootable. This step will automatically format the drive and create separate partitions for OS image and free space. The partion of OS image is protected. 
1. Alternatively, plug in the usb. Identify it in `/dev/`. (Say it is /dev/sda). Then `sudo cp <imagefile> /dev/sda`. Note: sda not sda1!

### Windows

Creating the bootable USB for Windows is easy with Windows's official download application on official website. It will automatically format the disk, install OS image, and make the disk bootable. 

## Boot Order

Certain computer systems has 2 or more physical storage disks, usually one of smaller size and quicker speed and another greater storage but slower speed. The OS is usually installed in the smaller disk for faster booting. 

Two complications are caused by this design: 1) sometimes the booting software (such as UEFI) is only installed in the smaller disk; 2) for certain OS the separate disk needs to be mounted manually.

If 1) is the case, erasing the smaller disk and installing the system into the larger disk will make the computer non-bootable. 
As to complication 2, mounting physcial hard drive is different for different system (windows usually have automatic mounting). For linux system, mounting a new physical disk usually requires fstab.

### Mounting new physical drive on Ubuntu.

- format the drive in ext4 format, mark its UUID
- append the following line to the file `/etc/fstab`

```
UUID=<UUID> <directory_to_mount> ext4 default 0 0
```
- enter `<directory_to_mount>` and execute the command `sudo mount -a`
