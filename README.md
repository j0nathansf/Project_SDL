# Project_SDL

## Prerequisites

First make sure you have *SDL* installed in your machine.

SDL is a "simple" media layer written in C++.
It is used for indie games for instances.

This is the steps to follow to install it on your Linux machine.


Install the packages via
```bash
sudo apt install libsdl2-2.0-0 libsdl2-dev libsdl2-image-2.0-0  libsdl2-image-dev
```

Now the tricky part, there is no "default" cmake package for sdl2_image
so create the folder
```bash
sudo mkdir /usr/lib/x86_64-linux-gnu/cmake/sdl2_image
```
create the file
```bash
sudo nano /usr/lib/x86_64-linux-gnu/cmake/sdl2_image/sdl2_image-config.cmake
```
and paste
```bash
set(prefix "/usr")
set(exec_prefix "${prefix}")
set(libdir "${prefix}/lib/x86_64-linux-gnu")
set(SDL2_IMAGE_PREFIX "/usr")
set(SDL2_IMAGE_EXEC_PREFIX "/usr")
set(SDL2_IMAGE_INCLUDE_DIRS "${prefix}/include/SDL2_image")
set(SDL2_IMAGE_LIBRARIES "-lSDL2_image")
link_directories("${prefix}/lib/x86_64-linux-gnu")
```

and you should be good to go.

## Installation

Create build directory

```bash
mkdir build
cd build
```

generate the build files

```bash
cmake ..
make
```

and finally, execute the application.


```bash
././src/main <nb_sheep> <nb_wolf> <duration>
```

Enjoy !
