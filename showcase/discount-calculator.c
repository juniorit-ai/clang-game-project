#include <stdio.h>

int main()
{
  float purchaseAmount, discountAmount, discountedPrice;

  // Prompt the user to enter the amount of their purchase
  printf("Enter the amount of your purchase: ");
  scanf("%f", &purchaseAmount);

  // Check if the purchase amount is greater than $100
  if (purchaseAmount > 100)
  {
    // Calculate the discount
    discountAmount = purchaseAmount * 0.1;
  }
  else if (purchaseAmount > 50)
  {
    // Calculate the discount
    discountAmount = purchaseAmount * 0.05;
  }
  else
  {
    // No discount
    discountAmount = 0;
  }

  // Calculate the discounted price
  discountedPrice = purchaseAmount - discountAmount;

  // Print the discounted price
  printf("Discounted price: $%.2f\n", discountedPrice);

  return 0;
}