#include <stdio.h>

int main()
{
  int grade;

  // Ask the user to input a numerical grade
  printf("Enter the grade: ");
  scanf("%d", &grade);

  // Check the grade and print the corresponding letter grade
  if (grade >= 90)
  {
    printf("A\n");
  }
  else if (grade >= 80 && grade <= 89)
  {
    printf("B\n");
  }
  else if (grade >= 70 && grade <= 79)
  {
    printf("C\n");
  }
  else if (grade >= 60 && grade <= 69)
  {
    printf("D\n");
  }
  else
  {
    printf("F\n");
  }

  return 0;
}