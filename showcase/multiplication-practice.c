#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  srand(time(0));
  int num1 = rand() % 10 + 1;
  int num2 = rand() % 10 + 1;
  int answer = num1 * num2;
  int userAnswer;

  do
  {
    printf("What is %d x %d? ", num1, num2);
    scanf("%d", &userAnswer);
    if (userAnswer == answer)
    {
      printf("Congratulations! That's correct.\n");
      break;
    }
    else
    {
      printf("Incorrect answer. Please try again.\n");
    }
  } while (1);

  return 0;
}