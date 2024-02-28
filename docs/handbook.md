### 1. "Hello, World!" in C
The "Hello, World!" program is often the introductory program for learning C, demonstrating the basic structure of a C program and how to output text to the console.

**Basic Structure of a C Program**
1. `#include<stdio.h>` - Includes the Standard Input/Output library, which provides functions for input and output operations.
2. `int main()` - The starting point of the program where execution begins.
3. `printf("Hello, World!\n");` - Outputs the text "Hello, World!" followed by a newline character to the console.
4. `return 0;` - Signals the end of the main function, returning 0 indicates that the program executed successfully.

**Example Code**
```c
#include <stdio.h>

int main() {
    printf("Hello, World!\n"); // Display message followed by a newline
    return 0;
}
```

### 2. Linux Shell Command Basics
A fundamental understanding of Linux shell commands is crucial for navigating directories, managing files, and executing C programs in a Linux environment.

**Navigating Directories**
1. `pwd` - Prints the current working directory.
2. `cd` - Changes the current directory.
3. `mkdir -p` - Creates directories and their parent directories as needed.
4. `ls -l` - Lists the contents of the current directory with details.

**Working With Files**
1. `touch` - Creates a new file.
2. `cat` - Displays the content of a file.
3. `cp` - Copies files or directories.
4. `mv` - Moves or renames files or directories.
5. `rm` - Removes files or directories.

**Project Build**
1. `make` - Builds and manages the project from source code.

**JuniorIT's Special Shell Commands**

1. `jcode` - Opens a file with the Code Editor.
2. `jcscript` - Runs C/C++ source code directly, similar to other scripting languages.
3. `juniorit` - Manages JuniorIT assignments.

**Code Example**
```sh
pwd                  # Print the current directory
ls -l                # List files and directories with details
mkdir -p path/to/dir # Create directory and its children directories
cd path/to/dir       # Change to specified directory
touch file.txt       # Create a new file named 'file.txt'
# Prints the string 'hello world' and redirects the output to 'file.txt'
echo "hello world" > file.txt      
rm file.txt          # Delete 'file.txt'

juniorit get         # Checks out your starter project for the assignment
jcode test.c         # Opens the file test.c in the Code Editor from the terminal
jcscript test.c      # Runs the test.c file as a script

make                 # Builds your starter project
make clean           # Removes any cached build files
make run             # Tests your starter project
make deploy          # Deploys your game to your personal website for public access
make submit          # Submits your code for review; It is the same as the command `juniorit submit`
```

### 3. Compile and Execute C Program
Compiling a C program turns the source code into an executable file,while executing runs the compiled code.

**Compilation**
1. `gcc` - The GNU C Compiler, used to compile C programs.
2. `gcc program.c` - Compiles `program.c` into an executable named `a.out` by default.
3. `gcc -o output program.c` - Compiles `program.c` into an executable named `output`, specifying the output file name.

**Execution**
1. `./program` - Execute the compiled program with the specified name (`program`).

**Code Example**
```bash
gcc HelloWorld.c   // Compiles the code. Check for any compilation errors or warnings.
./a.out            // Executes the compiled program.

gcc -o HelloWorld HelloWorld.c // Compiles the code with a specified output name.
./HelloWorld                    // Executes the compiled program.
```


### 4. Comments in C
Comments are integral for explaining the code, making it more readable and maintainable. They are ignored by the compiler and can also be used for temporarily disabling code.


**Key Knowledge Points**
1. **Single-line Comments**: `//` - Used for short explanations or annotations on a single line.
2. **Multi-line Comments**: `/* ... */` - Suitable for longer explanations that span multiple lines.
3. **JuniorIT's Special Comments**: `/*+ +*/` - These comments are for instructions to students, and the AI will ignore these comments.

**Code Example**
```c
/*+ 
JuniorIT's Special Comments
The AI will ignore these contents
+*/
#include <stdio.h>

int main() {
    // This is a single-line comment
    printf("Code is more understandable with comments!\n");

    /*
        This is a multi-line comment.
        It can span several lines.
    */

    return 0;
}
```