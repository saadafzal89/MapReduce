# MapReduce
This project implements a simple map reduce program in C for the words in a file and their count for each word respectively

The code is contained within 3 files namely:
1. mapper.c
2. reducer.c
3. combiner.c

"mapper.c" takes input from command line, which is a file to be read from.
It extracts single words and generates a key-value pair in the form of '(word,1)'.
The result of the program is written on STDOUT.

"reducer.c" reads the output of the above program from STDIN to count the number of times a particular word is repeated 
and displays the result on STDOUT in the form of key-value pair as '(word, count)'.

"combiner.c" is the parent program which uses fork() & exec() function to create and invoke the 2 child programs 
mentioned above.
It uses pipe() function to write on one end using mapper and read from other end using reducer.

Also, a shell script is included that compiles all 3 files to generate executables for the same. 
Run the script (./compiler_script) after granting it chmod 755 permission.
