<?php
// Ask the user to input a numerical grade
$grade = readline("Enter your grade: ");

// Convert the grade to integer
$grade = (int)$grade;

// Check the grade and print the corresponding letter grade
if ($grade >= 90) {
    echo "A";
} elseif ($grade >= 80) {
    echo "B";
} elseif ($grade >= 70) {
    echo "C";
} elseif ($grade >= 60) {
    echo "D";
} else {
    echo "F";
}

echo "\n";