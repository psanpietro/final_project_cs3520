# Final Project CS3520

The original project idea that I submitted was to use the aubio library in conjunction with the AudioFile library 
to create a text based program to input audio files and modify them using the aubio library. That project failed. 
I was unable to understand the aubio library, I ended up switching to the libsndfile library to read audio files 
which did seem to work but within aubio I was unable to understand the documentation about how to perform 
transformations to the audio itself, the library relied on the user understanding audio as it is stored on a computer,
I do not understand that and ran into countless difficulties. 

So that led me to completely change my project within the last 3 days that I had to create a project. I ended up using
ImGui and SFML as my two libraries and made use of the ImGui-sfml integration that was built with these two libraries 
directly in mind, so I ended up using three libraries for my new project. The new project was to create a game manager
that would be populated with multiple simple games using GUI elements and model controller designs. I ended up trying to
create Pong, Galaga and Snake. I was able to create Pong successfully, but I encountered many errors within the other two.
In Galaga the largest issue was that I was unable to figure out how to force certain methods to be ran at a faster speed 
in order to check for collisions. In Snake I struggled to prevent collision checking from adjacent elements within the 
moving snake. I left both of them in to demonstrate that I did use the libraries more that would initially be seen.
I also implemented a GameSelecter GUI that did allow for picking of games, however it also caused a terrible graphical glitch
that would cause the window and whatever game was on it to flash rapidly so I had to scrap the idea since I was not able to fix it.

Libraries used:
ImGui:
https://github.com/ocornut/imgui
SMFL:
https://github.com/SFML/SFML
ImGui-SFML
https://github.com/SFML/imgui-sfml

## How To Run The Program

In order to run the program, OpenGl needs to be installed with a couple xlib APIs.
These can be installed with these commands:

          sudo apt-get install libx11-dev libxrandr-dev
          
          sudo apt-get install libgl1-mesa-dev
          
          sudo apt-get install libudev-dev

The program relies on command line inputs to pick the game. Those three commands are: pong, galaga, snake. There is a 
-t input as well that shows that the project will compile on GitHub and therefore other systems.

Pong Controls:

Left Paddle is controlled by W and S. Right Paddle is controlled by Up and Down.

Galaga Controls:

PlayerShip is controlled by Left and Right and Spacebar for laser.

Snake Controls:

Up, Left, Right, Down are the movement controls.

Pong In Action:
![image](https://github.com/psanpietro/final_project_cs3520/assets/132850603/22e4e1e9-a5d9-4fac-9460-d3c136089d16)
