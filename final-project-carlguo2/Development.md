## This is a markdown file

### Code Review 1
Created all of my classes relevant for creating a basic game. 
Took a while to actually get the project to generate with the addon. Later had to manually 
add on the ofxOSC addon using the openFrameworks nuget extension.
I kept getting an error that my png image for player wasn't found and later learned
I needed to store the image inside my bin folder. Also had a problem where keyPressed() could 
only take one key parameter so in order to get the player to be able to move diagonally, created own 
booleans to return whether a key was pressed or not. Had to adjust a lot of dimensions and values since I 
used the Snake game as reference and will plan on creating variables to avoid magic numbers. Next week will
plan to get game sense collision, display score, have audio, and high score list. 

### Code Review 2
Monday - 
Worked on getting collision to work. Had to adjust what counted as a "collision" in order to improve gameplay.
Finished implementing LevelController as well, now the program counts when to spawn another enemy. Had to adjust
that value as well to make gameplay more interesting. Had a bug where enemies kept spawning on the screen, managed to
solve it after realizing that I was setting current_state to IN_GAME rather than START in the setup. Also finished 
getting transitions between START, IN_GAME, END state to work through keyPress. Ran into small problem where game 
wasn't resetting properly and crashed. Turns out I shouldn't use default constructor for player when I didn't implement 
it. Used player.setup to reset player instead. Next will be adding score to the screen, debugging to make sure that the 
enemy and bullets properly disappear when they go offscreen or when collision is made.

Thursday - 
Had a lot this week but managed to debug bullet and enemies vector. Both work as intended. Will probably tweak the game to 
make gameplay more enjoyable 

Friday - 
Found a bug where game would crash if I tried to shoot but was in contact with the enemy. Had to test a lot to narrow down why game
was crashing. I made it so the player can't shoot at a certain distance from the enemy in order to work around this bug. Added a start screen
and game font into the game, based this from the ofbook example. Also created the extra life power up that will be linked to ofxOSC library. 
Created a pause gamestate and divided program up into more methods. Also created a high score vector to hold and display high scores at the
end of the game. However had a problem where the score would not display. it turned out that I was not resetting my high score boolean flag.

### Code Review 3

