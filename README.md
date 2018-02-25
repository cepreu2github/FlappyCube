FlappyBird clone for PC written with SFML (Simple and Fast Multimedia Library) but with VERY simplified gameplay and physics.

# Building

Linux:

* Make sure that you have sfml libs installed. (`sudo apt-get install libsfml-dev libcsfml-dev` at Debian and Debian-based distros)
* Copy FindSFML.cmake from your sfml installation into cmake_modules folder. Example for debian: `cp /usr/share/SFML/cmake/Modules/FindSFML.cmake cmake_modules/FindSFML.cmake`
* Open terminal in project folder.
* `mkdir build && cd build`
* `cmake .. && make`
* `cp ../tileset.png ./ && cp ../font.ttf ./`
* run the game (`./FlappyCube`) :) 
