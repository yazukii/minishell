#!/bin/bash

# Define the name of your compiled C program
program="./a.out"

# Test 1: Echo a simple string
output=$(echo "Hello, World!" | $program)
expected="Hello, World!"
if [ "$output" = "$expected" ]; then
    echo "Test 1: Passed"
else
    echo "Test 1: Failed"
fi

# Test 2: Echo with escape sequences
output=$(echo "This is a\ttab\nNew line" | $program)
expected="This is a    tab
New line"
if [ "$output" = "$expected" ]; then
    echo "Test 2: Passed"
else
    echo "Test 2: Failed"
fi

# Test 3: Echo with special characters
output=$(echo "Special characters: \\ \\\" \$ \'" | $program)
expected="Special characters: \\ \" \$ '"
if [ "$output" = "$expected" ]; then
    echo "Test 3: Passed"
else
    echo "Test 3: Failed"
fi

# Test 4: Echo with option flag (-n)
output=$(echo -n "No trailing newline" | $program)
expected="No trailing newline"
if [ "$output" = "$expected" ]; then
    echo "Test 4: Passed"
else
    echo "Test 4: Failed"
fi

# Test 5: Echo multiple arguments
output=$(echo "Argument 1" "Argument 2" "Argument 3" | $program)
expected="Argument 1 Argument 2 Argument 3"
if [ "$output" = "$expected" ]; then
    echo "Test 5: Passed"
else
    echo "Test 5: Failed"
fi

# Test 6: Echo an empty string
output=$(echo "" | $program)
expected=""
if [ "$output" = "$expected" ]; then
    echo "Test 6: Passed"
else
    echo "Test 6: Failed"
fi

# Add more tests as needed...

# Cleanup (optional)
# rm -f your_program

echo "All tests completed."
