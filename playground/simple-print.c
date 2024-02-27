#include <stdio.h>

int main() {
    int number = 10;

    const char* message = "Hello, world!";

    printf("The number is: %d\n", number);

    printf("%s\n", message);

    printf("Number: %d, Message: %s\n", number, message);

    return 0;
}