Elijah Gonzalez, elgonzalez@wpi.edu

Platform- Windows 10

Files(Have headers)- Clock, Event, EventStep, GameManager, LogManager, Manager, Object, ObjectList, ObjectListIterator, Saucer, utility, Vector, WorldManager, game.cpp
(no headers) dragongly.log, example_output.txt-> has sample output, TechGameDevEngine.vcxproj, TechGameDevEngine.vcxproj.filters, Debug folder( I dont think you need it but its included)

Code Structure- Event is a superclass of Eventstep. Events implement the Observer design pattern by passing messages to objects. EventStep is once such event that triggers every game step.
Manager is a superclass of GameManager, LogManager, and WorldManager(all of which are singletons). GameManager runs the game loop. LogManager handles output to dragonfly.log. WorldManager 
keeps track of the state of in game objects. Object is a superclass to the sample class Saucer, which was used for testing purposes. Additionally there is a ObjectList class 
that uses an array data structure for storing objects. The ObjectListIterator allows easy iteration over ObjectLists. The utility file holds static utility functions. 
Clock is used to keep track of time. Vector merely holds x,y coordinates.

How to compile- Use the vcxproj file to open the project in Visual Studio. 

-Note- My testing of my code all exist in the game.cpp class, which prints out logs to dragongly.log, as well as utilizes all the major classes through use of the GameManager, and adding 
objects to WorldManager. Additionally the file example_output.txt shows example output from the last time I ran game.cpp

