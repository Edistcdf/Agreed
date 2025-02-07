# Agreed
Agreed


## Build Container

``` bash
cd dev/
podman build -t agreed-dev .
```

## Starta container för qt

``` bash
podman run -it --rm \
       -e DISPLAY=$DISPLAY \
       -v /tmp/.X11-unix:/tmp/.X11-unix \
       -v <path-to>/Agreed:/workspace:z \
       localhost/agreed-dev
```
possibly `sudo setenforce 0`

## If using Wayland
``` bash
podman run \
	--userns=keep-id \
	-e QT_QPA_PLATFORM=wayland \
	-e GDK_BACKEND=wayland \
	--device /dev/dri \
	--security-opt label=typer:container_runtime_t \
	-e WAYLAND_DISPLAY=$WAYLAND_DISPLAY \
	-v /run/user/$(id -u)/$WAYLAND_DISPLAY:/run/user/$(id -u)/$WAYLAND_DISPLAY \
	-e XDG_RUNTIME_DIR=/run/user/$(id -u) \
	-e WAYLAND_DISPLAY=$WAYLAND_DISPLAY \
	--privileged --rm -it -e DISPLAY=$DISPLAY -v ${HOME}/.profile:${HOME}/.profile -v ${HOME}/.bashrc:${HOME}/.bashrc -v <path-to>/Agreed/:/workspace localhost/dev
```
