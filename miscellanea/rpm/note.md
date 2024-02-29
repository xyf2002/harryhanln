Comment:

It seems the documentation of rpm publishing on fedora copr poor, and design outdated. I choose to not wasting my time digging into their obscurity.

# RPM 

Package a rpm pacakge and share it on copr.

Requirements:

```
sudo dnf install fedora-packager fedora-review
sudo usermod -a -G mock <your_local_username>
```

You need to have a fedora account. 


## Prep

Set up tree in your HOME with:

`rpmdev-setuptree`
