# GameOfLife
## This is a game of life project that consist four frout steps

```
For this project we used 
1.Cunit library for unit testing of our functions
2.Doxygen for documenting our program
3.Cmake for building and compiling our program 
4.SDL2 for create a good looking interface for our program
```



Also We created several version of yml file for CI,namely simple c.yml that worked with makefile and then we rewrote it to cmake.yml to work with cmake 


#Step 1
For step one we created a simple program that runs in terminal.You can get this step by using a release with Tag GameOfLife_v1.0.0
---
#Step 2
In this step we replaced the initial c.yml with cmake.yml and rewrote our project by creating a structure that was proposed by you.
Basically, we split the logic of our program into different folders for.ex game and console folders.
You can get this step by using a release with Tag GameOfLife_v2.0.0
---
#Step 3
Now in this step we are using SLD2 to create an interface to our game,so it doesn't use terminal anymore and runs in the separate window.
You can get this step by using a release with Tag GameOfLife_v3.0.0
---
#Step 4
This final step.In this step we added unit test to our project and created an doxygen documentation.
You can get this step by using a release with Tag GameOfLife_v4.0.0
---

# How to execute our program
After cloning our project create a building directory and the build project
```
1.mkdir Build
2.cd Build
3.cmake ../
4.cmake --build .
```
This will create two executable files tests and Game_of_Life
if you want to see the unit test write 
```
5. ./tests
```
and if you want to see the game itself write 
```
6. ./Game_of_Life
```


## Additional Features of our program
When program is running 
- 1.you can press space button to pause the game or start the game if it is paused 
- 2.you press the r button to restart the board,in case if cells do not change from one generation to the next

### documentation
For the documentation please you the link 
https://balayev.alwaysdata.net/life/

#### Docker
In this project we tried to use dockerfile.We tried our best , but attempt was unsuccessful.Because right now,
for us it is hard to run a GUI application from docker container.We managed to build our project with docker file and run test inside a docker container by using exec.You can you our docker file by writing:
1. docker build -t game.
2. docker run exec -it [Container_ID] bash
Then enter to the Build directory and run 
3. /tests
