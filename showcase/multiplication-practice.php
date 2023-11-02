<?php

// Generate two random numbers between 1 and 10
$num1 = rand(1, 10);
$num2 = rand(1, 10);

// Calculate the correct answer
$correctAnswer = $num1 * $num2;

// Initialize the user's answer variable
$userAnswer = null;

// Keep asking the user for the correct answer until they get it right
while ($userAnswer != $correctAnswer) {
    // Generate the multiplication question
    echo "What is " . $num1 . " x " . $num2 . "? ";

    // Get the user's answer
    $userAnswer = readline();

    // Check if the user's answer is correct
    if ($userAnswer == $correctAnswer) {
        echo "Congratulations! You got it right!";
    } else {
        echo "Oops! That's incorrect. Please try again.";
    }
}

echo "\n";