/*+
  Here is JuniorIT.AI's custom comment style, intended solely for instructional purposes, 
  and will be ignored by JuniorIT.AI's AI system. 
  In this editor, all comments are displayed in green to enhance code readability.
+*/

#include <stdio.h> // Include the standard input/output library

/* 
  The main function marks the beginning of program execution. It can also be written as `int main()` 
  if no command line arguments are required. 
  Whitespace and commands are ignored by the C compiler. 
  You to add comments or whitespace to enhance the readability of your code.
*/
int main (int argc /* argc is the number of command line arguments */, char *argv[] /* argv is an array of command line arguments */)
{   // Start of the main function block, Curly braces {} define the scope of functions, statements, and blocks in C

    /*
      Print "Hello, World!" followed by a newline to the screen
      The semicolon ; marks the end of the statement
      The \n is a newline character, which moves the cursor to the next line
    */
    printf("Hello, World!\n");

    return 0; // Return 0 to the operating system, indicating successful execution
}  // End of the main function block
