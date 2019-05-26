#!/bin/bash

if ! [ -e ./SDL ]
then
	git clone https://github.com/vinzmq/SDL_lib.git SDL
fi
make
./aero_hockey
