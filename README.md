# Agreed
Agreed


## Build Container
cd dev/
podman build -t agreed-dev .
## Starta container för qt

``` bash
podman run -it --rm \
       -e DISPLAY=$DISPLAY \
       -v /tmp/.X11-unix:/tmp/.X11-unix \
       -v <path-to>/Agreed:/workspace:z \
       localhost/agreed-dev
```
possibly `sudo setenforce 0`
