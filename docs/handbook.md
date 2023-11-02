## In this Session, Students Should Master the Following AI Prompts:

### Section - 1 : Let's explore some basic game technologies with AI. 

1. What is the game frame rate, and why is it important?

2. What is a sprite in game development?

3. How do you make the game background move to create the illusion of a sprite running infinitely?

4. Why can learning game development help developers gain a deeper understanding of coding and computer technologies?

### Section - 2 :  Why we start by learning C as our first coding language.

5. Please give me a brief history of the C language.

6. Which type of project is best suited for C as its coding language?

7. Please compare the C language with other popular coding languages.

8. Why can I learn other languages easily once I have learned the C language?

### Section - 3 : Set up your Linux development environment instantly.

9. What is github.com, and why is it important to developers?

10. What is VS Code, and what are VS Code extensions used for?

11. What is GitHub Codespaces? Can I use it for free?

12. I am new to Linux. Can you provide some basic Linux shell commands for practice?

13. What is 'sudo' in Linux commands, and how do I use it?

### Section - 4 : Discover the basic coding concepts

14. What is the purpose of the "Hello, World!" program in a coding language?

15. Please write a "Hello, World!" application in C?

16. Does my program need the main function in C, and what is its purpose?

17. How do I write single-line comments in C?

18. How do I write multi-line comments in C?

19. Does whitespace matter in C?

20. Do I need curly braces in C, and what is their purpose if they are needed?

21. Do I need to use semicolons in the end of each line in C?

22. What is the syntax of an if-else logic statement in the C programming language?

23. What is the syntax of a while loop statement in the C programming language?

24. Why does a PHP script start with `<?php`?

25. Please compare the syntax of C and PHP; what are the differences?


## Exploring Various Comment Types and Their Syntax:

### Section 1 : Comments in C

1. Single-Line Comments:

You can use double forward slashes (//) to write single-line comments in C. 

```c
// This is a single-line comment

int x = 10; // This comment is at the end of a line of code
```

2. Multi-Line Comments:

C also supports multi-line comments, which are enclosed within /* and */ markers. 

```c
/*
  This is a multi-line comment.
  It can span across multiple lines.
  These lines are all comments and are ignored by the compiler.
*/

int y = 20;

/*
  You can also use multi-line comments to temporarily exclude code:
  int z = 30;
*/

int a = 40;
```
### Section 2 : JuniorIT.AI's special comments :

Starts with /*+ and ends with +*/, AI will ignore these comments automatically.

```

/*+
  Please follow these steps in the code editor to have AI complete the task for you:

  1. Without selecting any text, right-click to open the context menu and choose the "JuniorIT.AI: Do It for Me" option.
  2. Alternatively, highlight all the comments below, then right-click and select the same option from the context menu.
  3. As a third option, you can type all the requirements in a single line and then execute the command by pressing 'Ctrl' + 'Enter'.

  Once the code finished, please run shell command "jcscript discount-calculator.c" in the playground directory to test your code.
+*/

```
### Section 3 : JuniorIt VS Code Extension Comments :

You can add a comment in your code file like this: // TODO: Fix the code error. Then, press Ctrl+Enter. The AI will help you complete the code.

```c
// TODO: fix the code error
#include <stdio.h>

int main() {
    printf("Hello, world!\n"
    return 0;
}
```

## Basic coding concepts in C:

### Section 1 : Making Decisions with If-Else Statements 

```c
if (condition) {
    // Code to be executed if the condition is true
} else {
    // Code to be executed if the condition is false
}
```

**Example** :

```c
int y = 3;
if (y > 5) {
    printf("y is greater than 5\n");
} else {
    printf("y is not greater than 5\n");
}
```

### Section 2 : while loop 

```c
while (condition) {
    // Code to be executed repeatedly as long as the condition is true
}
```
**Example** :

```c
int count = 0;
while (count < 5) {
    printf("Count: %d\n", count);
    count++;
}
```