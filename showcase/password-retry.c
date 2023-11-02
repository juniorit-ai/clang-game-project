#include <stdio.h>
#include <string.h>

int main()
{
  char password[20] = "password123"; // Set the correct password
  char input[20];                    // Variable to store user input

  int attempts = 3; // Number of attempts allowed

  while (attempts > 0)
  {
    printf("Enter the password: ");
    scanf("%s", input);

    // Check if the input matches the correct password
    if (strcmp(input, password) == 0)
    {
      printf("Access Granted\n");
      break;
    }
    else
    {
      attempts--;
      printf("Access Denied\n");
      printf("Attempts remaining: %d\n", attempts);
    }
  }

  // Check if all attempts are used
  if (attempts == 0)
  {
    printf("Access Denied\n");
  }

  return 0;
}