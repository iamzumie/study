In this link you can see your updated project:

Changes I had to make to get it running:
- Online Visual Studio didn't recognise conio.h so i had to change it to string.h

Changed i made: 
- Overall reading of the code, more comments for example.
  Renamed the function choose to input.

- The function gets() has been removed <stdio.h> from C11 standard. 
  gets() doesn't protect against the buffer overrun so you should never use gets() and use fgets() instead.
  This will solve your trailing newline where you tried to fix it with the function bettersgets ;)

- I created a seperate function for the title screen & intro named startUp

- For the first couple of questions i changed it so it keeps repeating if input isn't correct with a do..while statement

- Second question: When people have to enter their age, i was hoping to get it so it has to be numeric but couldn't get it working YET with isdigit.
  I did change the datatype to %i because whenever i tried to fill in a negative value it just passes.

- At line 177 i added a getchar so it removes my newline (otherwise it already gives and error at commgen

- Simple changed like the init common command center. int i = 0 is easier than init i first and then give it a value.


