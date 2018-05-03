# CS 126 FinalProject
## Space Shooter Game

### What is This?
This is a C++ space shooter game that I made for CS 126 project using the standard ofMain library. I also used ofxOSC as an addon
in order to make a controller from my phone that I can play the game from. The OSC application I used is called touchOSC which
is an OSC application for Windows and iOS or Android. The OSC interface I used to make my game is on the github as controllerInterface.touchosc

The game's premise is to simply shoot as many enemies as one can without getting hit. The game keeps track of the top 5 high scores using similar 
code as from the ofSnake program. I also used ofSoundPlayer, ofTrueTypeFont, and ofImage to create the audio, text, and characters in this game. 
The assets were mainly taken from google images or from assets people sent out (see "Where I got Everything"). The game has four game states:
START, IN_GAME, PAUSED, and END. 

### How to Play
Just simply run the program to start the game.
For keyboard controls: 
- 'w' is to move up
- 'a' is to move left
- 's' is to move down
- 'd' is to move right
- mouse left button is to shoot
- 'p' is to pause the game
- 's' is to start the game if the game is in START game state
- 'r' is to restart the game if the game is in the END game state
- 'c' is to close the game if the game is in the END game state

The touchOSC controller will tell which button does what.
If one wants to play with the keyboard controls, go to src/ofApp and set bool is_testing_ to false.
If one wants to play with the controller then set bool is_testing_ to true.

### Where I got everything
The OSC controller commands are made possible with touchOSC.
Where I got my assets:
I pulled them off of Google Images but these were the links I found them at  
[Player](https://www.reddit.com/r/kenneyland/comments/2z84kk/tutorial_creating_a_spaceship_game_asset/)  
[Enemies](http://docs.garagegames.com/torquex/official/content/documentation/TorqueX%202D/Tutorials/images/evilFighter.png)  
[Bullets](http://forum.entitygaming.com/showthread.php?1380-Custom-Crosshairs!)  
[Start Screen](https://itch.io/jam/flying-toast-with-jam/rate/13518)  
[Laser Audio from dklon](https://opengameart.org/content/laser-fire)

### Thanks to 
My roommate Matt for giving feedback and helping with the OSC controller interface and the game in general.