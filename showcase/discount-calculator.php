<?php

// Step 1: Ask the user for the amount of their purchase
$purchaseAmount = readline("Enter the amount of your purchase: ");

// Step 2: Check if the purchase amount is greater than $100
if ($purchaseAmount > 100) {
    // Step 3: Apply a 10% discount to the purchase amount
    $discountedAmount = $purchaseAmount * 0.9;
} elseif ($purchaseAmount > 50) {
    // Step 4: Check if the purchase amount is greater than $50
    // Step 5: Apply a 5% discount to the purchase amount
    $discountedAmount = $purchaseAmount * 0.95;
} else {
    $discountedAmount = $purchaseAmount;
}

// Step 6: Print the discounted amount
echo "Discounted amount: $" . $discountedAmount . "\n";
