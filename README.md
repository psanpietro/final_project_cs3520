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

## How To Run The Program

The program relies on command line inputs to pick the game. Those three commands are: pong, galaga, snake. There is a 
-t input as well that shows that the project will compile on GitHub and therefore other systems.