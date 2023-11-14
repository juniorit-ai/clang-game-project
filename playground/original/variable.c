/*+
  In the C programming language, the basic data types are the fundamental types used to define the nature of data that can be stored in a variable. 
  These basic types are:

  int: Used for integers. This data type can store both positive and negative whole numbers.
  float: Used to store floating-point numbers, i.e., numbers with a fractional part.
  double: Similar to float but with double precision, meaning it can handle larger numbers and more precise fractional parts.
  char: Used to store a single character. In C, a character is stored as an ASCII value.
  void: A special type that represents the absence of value. 

  Additionally, there are also some derived types like arrays, pointers, structures, and unions, 
  which are built using these basic data types. These derived types allow for more complex data structures and functionality.
+*/

#include <stdio.h>    // Include Standard Input and Output Library for functions like printf.
#include <string.h>   // Include String Library for string manipulation functions like strcpy.

/*
  `struct`, short for structure, is a composite data type that groups together variables under a single name. 
  These variables, known as members, can be of different data types.
  
  Define a struct named `GameSprite`.
*/
struct GameSprite {
    int x, y;         // 'int' data type for storing integer values for X and Y coordinates.
    float scale;      // 'float' data type for storing a floating-point number for the sprite's scale.
    char image[50];   // 'char' array to store a string (sequence of characters) for the sprite's image filename.
};

/* 
  `typedef` in C is a keyword used to create an alias for a data type. It essentially allows you to define a new name for an existing type. 
  Use keyword `typedef` to define a user data type Sprite for `struct GameSprite` type
*/

typedef struct GameSprite Sprite;

int main() {
    // Integer (int) data type to store whole numbers.
    int left = 100;   // Stores the horizontal position of the sprite as an integer.
    int top = left;   // Stores the vertical position of the sprite as an integer (assign the left value to top).

    // Float data type to store floating-point numbers (numbers with a decimal point).
    float scale = 1.5; // Stores the scale factor of the sprite as a floating-point number.

    // Pointer to a constant character (const char*). This is used for strings (text).
    const char* filename1 = "sprite1.png"; // Points to a string constant, storing the name of the image file.

    // Creating an instance of the GameSprite struct.
    struct GameSprite mySprite1;

    // Assigning values to the struct's members.
    mySprite1.x = left;      // Assigning integer value to 'x'.
    mySprite1.y = top;       // Assigning integer value to 'y'.
    mySprite1.scale = scale; // Assigning floating-point value to 'scale'.

    // Using strcpy to copy a string from 'filename' to 'mySprite.image'.
    strcpy(mySprite1.image, filename1); // 'filename' is a string (char array).

    // Printing the properties of the sprite using printf.
    printf("Sprite1 Position: (%d, %d)\n", mySprite1.x, mySprite1.y); // Printing integers with %d.
    printf("Sprite1 Scale: %f\n", mySprite1.scale); // Printing a float with %f.
    printf("Sprite1 Image: %s\n", mySprite1.image); // Printing a string with %s.


    printf("\n");

    Sprite mySprite2;

    // `Sprite` data type is just one alias of `struct GameSprite`, we can assign value directly between the same data type
    mySprite2 = mySprite1;

    mySprite2.x = mySprite2.x + 100;
    mySprite2.y = mySprite2.y + 100;
    mySprite2.scale = mySprite2.scale * 1.1;

    const char* filename2 = "sprite2.png";
    strcpy(mySprite2.image, filename2);

    printf("Sprite2 Position: (%d, %d)\n", mySprite2.x, mySprite2.y); // Printing integers with %d.
    printf("Sprite2 Scale: %f\n", mySprite2.scale); // Printing a float with %f.
    printf("Sprite2 Image: %s\n", mySprite2.image); // Printing a string with %s.

    return 0; // Return statement with an integer 0 indicating successful execution.
}

