#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <sys/select.h>

// Function to set the terminal in non-canonical mode
void setNonCanonicalMode()
{
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

// Function to check if a key is pressed
int isKeyPressed()
{
    struct timeval tv;
    fd_set fds;
    tv.tv_sec = 0;
    tv.tv_usec = 0;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv);
    return FD_ISSET(STDIN_FILENO, &fds);
}

// Function to get the pressed key
char getKeyPressed()
{
    char c = '\0';
    if (isKeyPressed())
    {
        read(STDIN_FILENO, &c, 1);
    }
    return c;
}

int main()
{
    // Set the terminal in non-canonical mode
    setNonCanonicalMode();

    // Set the frame rate
    int frameRate = 30;

    // Initialize ball position and direction
    int ballX = 0;
    int ballY = 0;
    int directionX = 1;
    int directionY = 1;

    // Game loop
    while (1)
    {
        // Clear screen
        system("clear");

        // Update ball position
        ballX += directionX;
        ballY += directionY;

        // Check if the ball hits the edges of the screen
        if (ballX >= 80 || ballX <= 0)
        {
            directionX *= -1;
        }
        if (ballY >= 24 || ballY <= 0)
        {
            directionY *= -1;
        }

        // Print ball at current position
        for (int i = 0; i < ballY; i++)
        {
            printf("\n");
        }
        for (int j = 0; j < ballX; j++)
        {
            printf(" ");
        }
        printf("O\n");

        // Check if the q key is pressed to exit the game
        if (getKeyPressed() == 'q')
        {
            break;
        }

        // Delay to control the frame rate
        usleep(1000000 / frameRate);
    }

    return 0;
}