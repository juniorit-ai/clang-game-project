<?php

$correctPassword = "password"; // Set the correct password here
$maxAttempts = 3; // Set the maximum number of attempts here

$attempts = 0; // Initialize the attempts counter

while ($attempts < $maxAttempts) {
    $attempts++;

    $enteredPassword = readline("Enter the password: "); // Prompt the user to enter the password

    if ($enteredPassword === $correctPassword) {
        echo "Access Granted" . PHP_EOL; // Display "Access Granted" message
        break; // Exit the loop if the password is correct
    } else {
        echo "Access Denied" . PHP_EOL; // Display "Access Denied" message
    }
}

if ($attempts === $maxAttempts) {
    echo "Max attempts reached. Access Denied" . PHP_EOL; // Display "Access Denied" message if maximum attempts reached
}

echo "\n";