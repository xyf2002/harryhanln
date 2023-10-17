# Docker Guide

## Quick Start

A Dockerfile can be used to create docker image. A docker image can be used to instantiate a docker container. 

A container is a isolated process on host machine, behaving like a VM. You can run app or test apps in the container.
A image defines the file system of the container. It shall contain all that is needed to run the process. 

A docker file defines the image:

```dockerfile
# Based on node:18-alpine image
FROM node:18-alpine 

# the working directory of the container
WORKDIR /app 

# copy all file current directory in host machine to current directory of the container (/app)
COPY . . 

# run the command 
RUN yarn install --production 

# also run this command
CMD ["node", "src/index.js"] 

EXPOSE 3000
```

## Quick Commands

### Creating Image

```bash
# build image from docker file
docker build -t <image-name> <path-to-directory-of-dockerfile>

# remove image 
docker rmi <image-id> 
```

### Running Container

```
# run container from image 
# Instantiate a container from the image and run it
docker run -p <host-port>:<container-port> <image-name> 

# list all running containers
docker ps

# list all containers
docker ps -a 

# execute command in container 
docker exec <container-id> <command> 

# access container's shell
docker exec -it <container-id> /bin/sh

# stop container 
docker stop <container-id> 

# remove container 
docker rm <container-id> 
```

### Pushing and Pulling Image

```bash
# pull image from docker hub 
docker pull <docker-hub-username>/<image-name>:<tag>

# login to docker hub
docker login

# tag image 
docker tag <image-id> <docker-hub-username>/<image-name>:<tag> 

# push image 
docker push <docker-hub-username>/<image-name>:<tag> 
```

## Volume and Bind Mount

### Volume 

Each container instantiated from an image by defaults are independent. To preserve data between different images instantiated from the same container, we may create a docker volume. 

A docker volume is an abstraction of a directory in the host machine managed by docker which can stored data that container can access.

To create a volume, we can use the following command:

```bash
docker volume create <volume-name>
```

To use the volume, we can use the following command:

```bash
docker run --mount type=volume,src=<VolumeName>,target=<FileInContainer> <image-name>
```

The `<FileInContainer>` is the path to the file in the container that we want to mount the volume to; i.e., it contains all the data stored in `<VolumeName>`. Any changes of the `<FileInContainer>` will also be recorded in the volume.

### Bind mount

A bind mount is similar to a volume, but it is not managed by docker. It is simply a directory in the host machine that is mounted to the container. 

To use the bind mount, we can use the following command:

```bash
docker run --mount type=bind,src=<HostDirectory>,target=<FileInContainer> <image-name>
```
