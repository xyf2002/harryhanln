# Based on node:18-alpine image
FROM archlinux

# the working directory of the container
WORKDIR /app 

RUN pacman -Syyu --needed --noconfirm  
RUN pacman -S vim git typst --needed --noconfirm

CMD ["echo", "\'yes'"]
