/*+
  Please follow these steps in the code editor to have AI complete the task for you:

  1. Without selecting any text, right-click to open the context menu and choose the "JuniorIT.AI: Do It for Me" option.
  2. Alternatively, highlight all the comments below, then right-click and select the same option from the context menu.
  3. As a third option, you can type all the requirements in a single line and then execute the command by pressing 'Ctrl' + 'Enter'.
+*/

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