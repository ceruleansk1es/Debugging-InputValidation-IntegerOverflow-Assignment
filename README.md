# Debugging-InputValidation-IntegerOverflow-Assignment

CSCE 120 homework assignment, completion of various functions in C++
The file functions.cpp is where code was actually created.

This assignment, and primarily the modified functions.cpp file, contains implementations of several utility functions focused on basic arithmetic operations, logical decisions, and error-handling. The primary goal of these implementations, beyond correctness, is defensive programming (ensuring that invalid inputs and overflow conditions are properly handled using C++ exceptions).

Function Descriptions:
SumIsEven(int a, int b)
- Determines whether the sum of two integers is even.
- Adds the two inputs and checks if the result is divisible by 2.
- Returns true if the sum is even, otherwise false.

Largest(int a, int b, int c)
- Finds the largest of three integers.
- Iteratively compares values using a temporary variable.
- Avoids built-in functions like std::max to demonstrate manual comparison logic.

BoxesNeeded(int apples)
- Calculates how many boxes are required to store a given number of apples.
- Each box holds 20 apples.

  Logic:
  - If apples ≤ 20 → returns 1 box
  - If apples > 20 → returns the ceiling of (apples / 20)
  - If apples ≤ 0 → returns 0
  - Handles both exact and non-exact multiples of 20.

SmarterSection(int A_correct, int A_total, int B_correct, int B_total)
- Compares performance between two sections (A and B).
- Computes accuracy as:
  Section A: A_correct / A_total
  Section B: B_correct / B_total
- Returns true if Section A has a higher score.

  Error handling:
  - Throws std::invalid_argument if:
    Correct answers exceed total questions
    Any value is negative
    Total questions are zero or less

GoodDinner(int pizzas, bool is_weekend)
- Determines whether a dinner qualifies as “good” based on pizza count and timing.
- Returns true if:
  Number of pizzas is between 10 and 20 (inclusive), OR
  It’s the weekend and pizzas > 20
  Otherwise returns false

SumBetween(long long low, long long high)
- Computes the sum of all integers in the range [low, high] (inclusive).
- Key Features:
  Validates that low <= high
  Handles ranges that cross zero with special logic
  Iteratively accumulates the sum

  Error handling:
  - Throws std::invalid_argument if low > high
  - Throws std::overflow_error if the sum exceeds long long limits
  - Uses LLONG_MAX and LLONG_MIN to detect overflow before it happens

Product(long long a, long long b)
- Computes the product of two integers with explicit overflow protection.
- Key Features:
  Handles multiplication safely without directly risking overflow
  Uses division-based checks (e.g., a > LLONG_MAX / b) to detect unsafe operations

  Error handling:
  - Throws std::overflow_error for different overflow scenarios:
  = Positive overflow
  - Negative overflow
  - Mixed-sign overflow cases
