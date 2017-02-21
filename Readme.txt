READ ME

This is an event driven simulation of a coffee shop. Right now when you run the main file it will ask for the name of a txt file to read in. 
The syntax for this program is very specific so I will list it here.

You can order the following: TEA, DONUT, BAGEL, PANINI, ICEDCAPP
 - each one has its own constant order time which is multiplied by how many you order

 example of text from the text file:

 - 1 Arrive COFFEE 1 // this tells the program that a customer arrived at time 1 and ordered 1 coffee

 - 21 ARRIVE COFFEE 1 DONUT 5 // this tells the program that a customer arrived at time 21 and ordered 1 coffee and 5 donuts
 
 - 300 OPEN // this tells the program that at time 300 the express lane will open


the program should be spitting out feedback for every single command that it reads in. I.E customer wait time, who gets moved to express lane, etc.

To run my program type this into the command line

g++ -o A2 main.cpp Arrival.cpp CloseLine.cpp CompleteService.cpp Customer.cpp Event.cpp Node.cpp OpenLine.cpp PriorityQueue.cpp Shop.cpp StartService.cpp

then to run my program write 

A2 

to the command line it will ask you to input a file name this is the name of the txt file that you wish for the program to read in but make sure it is also in the folder that i sent you