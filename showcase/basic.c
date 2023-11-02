#include <stdio.h>
#include <unistd.h> // for usleep

int main()
{
    // Define the necessary variables
    int ballX = 0;         // current x-coordinate of the ball
    int ballY = 0;         // current y-coordinate of the ball
    int velocityX = 1;     // velocity of the ball in the x-direction
    int velocityY = 1;     // velocity of the ball in the y-direction
    int screenWidth = 80;  // width of the screen
    int screenHeight = 24; // height of the screen
    int frameRate = 30;    // frame rate in frames per second

    // Calculate the delay in microseconds based on the frame rate
    int delay = 1000000 / frameRate;

    // Infinite loop to continuously update the ball's position and redraw the screen
    while (1)
    {
        // Clear the screen
        printf("\033[H\033[J");

        // Update the ball's position
        ballX += velocityX;
        ballY += velocityY;

        // Check if the ball has reached the edge of the screen and change its direction
        if (ballX <= 0 || ballX >= screenWidth - 1)
        {
            velocityX = -velocityX;
        }
        if (ballY <= 0 || ballY >= screenHeight - 1)
        {
            velocityY = -velocityY;
        }

        // Draw the ball at its current position
        printf("\033[%d;%dH", ballY, ballX);
        printf("O");

        // Flush the output to display the changes
        fflush(stdout);

        // Delay for the specified amount of time
        usleep(delay);
    }

    return 0;
}