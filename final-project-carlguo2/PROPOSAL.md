# Project Proposal

## Carl Guo
## 4/10/18

### Project Description
For this project I am trying to create a simple [bullet hell game](https://en.wikipedia.org/wiki/Shoot_%27em_up).
The game will allow the player control a plane will trying to shoot down enemies shooting at you.The wave of enemies
never end and the score the player gets will be the amount of enemies the player shoots down before dying. This game will include
a high score list of 5, power ups, and audio (using ofsoundplayer). Using the openFrameworks OSC addon, I will make it so that this game able 
to be get signals from other devices (such as extra lives for the player or add more enemies to the screen.)
I got the idea for this project from an [openFrameworks example](http://openframeworks.cc/ofBook/chapters/game_design.html)

### Libraries Needed
I will be using the standard openFrameworks ofApp to create the base game and graphics. This will be similar to how the 
Snake game was programmed: high score list, audio, gamestates. I will use the [ofxOSC](http://openframeworks.cc/documentation/ofxOsc/) addon in order to be able to connect other 
devices to the game. I will most likely also need to use OpenGL to create a windowed application for this game.

### Goals
I will split the goals of my project into three steps:
1. Get a working demo of the game (working game with states and scoring)
2. Add power ups, audio, high score list, if not before then will add player, enemy, bullet, power up bitmaps (custom made or get from internet)
3. Get OSC functionality to work to be able to add things to the game and make it more difficult or easier.

### Experience 
I have had previous experience with game design. I took CS 199 GAM during Winter 2017 and learned how
make games and code in Unity. I am not completely sure if Unity will be entirely similar to this
new game engine library, but I believe the experience I have with Unity will prove useful. I have also programmed
a very similar game using javascript before in high school and may use that as reference for creating my base game.


### Update 
I took out the power up feature and used the osc addon to make a remote controller to play the game from there.