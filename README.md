# Agreed
Agreed


## Starta container för qt
givetvis måste man fixa path här
``` bash
podman run -it --rm \
       -e DISPLAY=$DISPLAY \
       -v /tmp/.X11-unix:/tmp/.X11-unix \
       --name my-dev \
       -v /home/enorlander/kod/Agreed:/workspace:Z \
       9cdd798a7f2123bb817799f13b300c83f2f7a34c752014c89c5f48ccd5248245 /bin/bas
```

På din host behlöver du eventuellt stänga av SE linux för att X ska forwardas OBS FARLIGT???
`sudo setenforce 0`
