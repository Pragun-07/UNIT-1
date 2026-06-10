# COMPREHENSIVE C PROGRAMMING GUIDE - UNIT 1
## Operators, Conditionals, and Logical Operations

---

## TABLE OF CONTENTS
1. [Operators](#operators)
2. [If-Else Statements](#if-else-statements)
3. [Else-If Ladder](#else-if-ladder)
4. [Logical Operators](#logical-operators)
5. [Bitwise Operators](#bitwise-operators)
6. [Switch Statement](#switch-statement)
7. [Precedence and Associativity](#precedence-and-associativity)
8. [Sequence Points](#sequence-points)

---

## OPERATORS

### 1.1 ARITHMETIC OPERATORS

#### Theory
Arithmetic operators perform mathematical calculations on numeric values.

| Operator | Operation | Example | Result |
|----------|-----------|---------|--------|
| + | Addition | 5 + 3 | 8 |
| - | Subtraction | 5 - 3 | 2 |
| * | Multiplication | 5 * 3 | 15 |
| / | Division | 7 / 2 | 3 (integer division) |
| % | Modulus | 7 % 2 | 1 |

#### Key Concepts
- **Integer Division**: When both operands are integers, the result is an integer (fractional part truncated)
- **Mixed Mode**: When one operand is float, automatic type conversion occurs
- **Operator Precedence**: `* / %` have higher precedence than `+ -`

#### Program: Arithmetic Operations
```c
#include <stdio.h>

int main()
{
    printf("----------ARITHMETIC OPERATIONS----------\n");
    
    // Basic operations
    printf("Addition: 2 + 3 = %d\n", 2 + 3);           // 5
    printf("Subtraction: 4 - 2 = %d\n", 4 - 2);        // 2
    printf("Multiplication: 4 * 2 = %d\n", 4 * 2);      // 8
    printf("Division: 5 / 2 = %d\n", 5 / 2);           // 2 (integer div)
    printf("Modulus: 5 %% 2 = %d\n", 5 % 2);           // 1
    
    // Mixed mode operations
    printf("\nMixed Mode Operations:\n");
    printf("25 / 4 (int/int) = %d\n", 25 / 4);         // 6
    printf("25.0 / 4.0 (float/float) = %f\n", 25.0 / 4.0); // 6.250000
    printf("25.0 / 4 (float/int) = %f\n", 25.0 / 4);   // 6.250000
    printf("25 / 4.0 (int/float) = %f\n", 25 / 4.0);   // 6.250000
    
    // Precedence
    printf("\nPrecedence (Multiplication before Addition):\n");
    printf("10 + 3 / 2 = %d\n", 10 + 3 / 2);           // 10 + 1 = 11
    printf("(10 + 3) / 2.0 = %f\n", (10 + 3) / 2.0);   // 13 / 2.0 = 6.500000
    
    // Character arithmetic
    printf("\nCharacter Arithmetic:\n");
    printf("'A' + 1 = %d (ASCII)\n", 'A' + 1);         // 66
    printf("'9' - '0' = %d\n", '9' - '0');             // 9
    
    // Type casting
    printf("\nType Casting:\n");
    printf("(float)(5/2) = %f\n", (float)(5/2));       // 2.000000 (cast after division)
    printf("(float)5/2 = %f\n", (float)5/2);           // 2.500000 (cast before division)
    
    return 0;
}
```

#### Step-wise Explanation
1. **Basic Operations**: Direct arithmetic calculations
2. **Integer Division**: 5/2 = 2 (not 2.5) - fraction is discarded
3. **Type Promotion**: 25.0/4 → 25.0/4.0 → 6.25 (automatic conversion)
4. **Precedence Rule**: 10 + 3/2 = 10 + (3/2) = 10 + 1 = 11
5. **Casting Priority**: (float)(5/2) first divides, then casts; (float)5/2 casts first

---

### 1.2 INCREMENT AND DECREMENT OPERATORS

#### Theory
- **Pre-increment (++a)**: Increment first, then use the value
- **Post-increment (a++)**: Use the value first, then increment
- Same logic applies to decrement (--a vs a--)

#### Diagram: Pre vs Post Increment
```
Pre-increment (++a):
   a = 5
   b = ++a;    → a becomes 6 FIRST
               → b gets 6
   Result: a=6, b=6

Post-increment (a++):
   a = 5
   b = a++;    → b gets 5 FIRST
               → a becomes 6 after assignment
   Result: a=6, b=5
```

#### Program: Increment/Decrement
```c
#include <stdio.h>

int main()
{
    printf("----------INCREMENT AND DECREMENT----------\n");
    
    // Post-increment
    int a = 5;
    a++;
    printf("Post-increment: a++ → a = %d\n", a);  // 6
    
    // Pre-increment
    int b = 5;
    printf("Pre-increment: ++b → %d\n", ++b);     // 6
    
    // Combination in expression
    printf("\nCombination of Pre and Post:\n");
    int x = 4;
    int y = x++ + ++x;
    printf("x = 4; y = x++ + ++x\n");
    printf("Step 1: Use current x(4) then increment → x becomes 5\n");
    printf("Step 2: Increment x first → x becomes 6, then use 6\n");
    printf("y = 4 + 6 = %d\n", y);  // 10
    printf("Final: x = %d, y = %d\n", x, y);
    
    // Using sequence points to avoid undefined behavior
    printf("\nWith Sequence Points (Safe):\n");
    int u = 6, z;
    int d = ++u;   // u becomes 7, d = 7
    int e = u--;   // e = 7, u becomes 6
    int f = --u;   // u becomes 5, f = 5
    z = d + e - f; // 7 + 7 - 5 = 9
    printf("d = %d, e = %d, f = %d, z = %d\n", d, e, f, z);
    
    return 0;
}
```

#### Step-wise Explanation
1. **Post-increment**: Current value is used, then incremented
2. **Pre-increment**: Value is incremented first, then used
3. **In Expressions**: Combination can lead to undefined behavior without sequence points
4. **Solution**: Use intermediate variables and sequence points (;)

---

### 1.3 RELATIONAL OPERATORS

#### Theory
Relational operators compare two values and return 1 (true) or 0 (false).

| Operator | Meaning | Example | Result |
|----------|---------|---------|--------|
| == | Equal to | 5 == 5 | 1 (true) |
| != | Not equal to | 5 != 3 | 1 (true) |
| > | Greater than | 5 > 3 | 1 (true) |
| < | Less than | 5 < 3 | 0 (false) |
| >= | Greater than or equal | 5 >= 5 | 1 (true) |
| <= | Less than or equal | 5 <= 3 | 0 (false) |

#### Important Note: Chaining Not Allowed
```
WRONG: 5 == 5 == 5
Evaluation: (5 == 5) == 5 → 1 == 5 → 0 (FALSE!)

CORRECT: (5 == 5) && (5 == 5) → 1 && 1 → 1 (TRUE)
```

#### Program: Relational Operations
```c
#include <stdio.h>

int main()
{
    printf("----------RELATIONAL OPERATORS----------\n");
    
    printf("5 == 5: %d\n", 5 == 5);           // 1 (true)
    printf("5 != 3: %d\n", 5 != 3);           // 1 (true)
    printf("5 > 3: %d\n", 5 > 3);             // 1 (true)
    printf("5 < 3: %d\n", 5 < 3);             // 0 (false)
    printf("5 >= 5: %d\n", 5 >= 5);           // 1 (true)
    printf("5 <= 3: %d\n", 5 <= 3);           // 0 (false)
    
    // Relational with logical
    printf("\nRelational + Logical:\n");
    printf("(5 == 5) && (5 == 5): %d\n", (5 == 5) && (5 == 5)); // 1
    
    // TRAP: Chained comparison (NOT allowed in C)
    printf("\nCHAINING TRAP:\n");
    printf("5 == 5 == 5: %d (WRONG!)\n", 5 == 5 == 5);
    printf("Explanation: (5 == 5) == 5 → 1 == 5 → 0\n");
    printf("Correct: (5 == 5) && (5 == 5): %d\n", (5 == 5) && (5 == 5));
    
    printf("\n10 > 5 > 1: %d (WRONG!)\n", 10 > 5 > 1);
    printf("Explanation: (10 > 5) > 1 → 1 > 1 → 0\n");
    
    // Character comparisons
    printf("\nCharacter Comparisons (using ASCII):\n");
    printf("'A' < 'a': %d (65 < 97)\n", 'A' < 'a');     // 1
    printf("'9' > '0': %d (57 > 48)\n", '9' > '0');     // 1
    
    // Assignment in relational expression
    printf("\nAssignment in Relational Expression:\n");
    int x;
    printf("(x = 5) == 5: %d\n", (x = 5) == 5);  // x is assigned 5, then compared
    
    return 0;
}
```

---

### 1.4 BITWISE OPERATORS

#### Theory
Bitwise operators work on individual bits of integers.

| Operator | Operation | Example |
|----------|-----------|---------|
| & | AND | 10 & 8 = 8 |
| \| | OR | 10 \| 8 = 10 |
| ^ | XOR | 10 ^ 8 = 2 |
| ~ | NOT | ~10 = -11 |
| << | Left shift | 10 << 2 = 40 |
| >> | Right shift | 10 >> 2 = 2 |

#### Diagram: Bitwise AND Operation
```
  10 = 1010
   8 = 1000
  --------
10 & 8 = 1000 = 8

Rule: 1 & 1 = 1, otherwise 0
```

#### Diagram: Left and Right Shift
```
Left Shift (n << k) means multiply by 2^k
  10 << 2 = 10 * 2^2 = 10 * 4 = 40
  
Binary: 1010 << 2 = 101000 (40)

Right Shift (n >> k) means divide by 2^k
  10 >> 2 = 10 / 2^2 = 10 / 4 = 2 (integer division)
  
Binary: 1010 >> 2 = 0010 (2)
```

#### Diagram: Bitwise NOT
```
~n = -(n + 1)  [shortcut formula]

For n = 10:
Binary (32-bit): 00000000 00000000 00000000 00001010
NOT operation:   11111111 11111111 11111111 11110101

Since MSB = 1, it's negative
To find magnitude: Flip bits and add 1
                  00000000 00000000 00000000 00001010
                                                    + 1
                  00000000 00000000 00000000 00001011 = 11

Result: -11
```

#### Program: Bitwise Operations
```c
#include <stdio.h>

int main()
{
    printf("----------BITWISE OPERATORS----------\n");
    
    int n = 10;  // Binary: 1010
    int m = 8;   // Binary: 1000
    
    printf("n = %d (Binary: 1010)\n", n);
    printf("m = %d (Binary: 1000)\n", m);
    printf("\nBitwise AND (n & m): %d\n", n & m);      // 8 (1000)
    printf("Bitwise OR (n | m): %d\n", n | m);        // 10 (1010)
    printf("Bitwise XOR (n ^ m): %d\n", n ^ m);       // 2 (0010)
    printf("Bitwise NOT (~n): %d\n", ~n);             // -11
    
    printf("\nShift Operations:\n");
    printf("Left shift (n << 2): %d (10 * 4 = 40)\n", n << 2);   // 40
    printf("Right shift (n >> 2): %d (10 / 4 = 2)\n", n >> 2);   // 2
    
    // Checking if number is odd/even using bitwise AND
    printf("\nCheck Odd/Even using Bitwise:\n");
    int num = 7;
    if (num & 1)
        printf("%d is ODD\n", num);
    else
        printf("%d is EVEN\n", num);
    
    // Check if number is power of 2
    printf("\nCheck Power of 2:\n");
    int p = 8;
    printf("%d is power of 2: %s\n", p, ((p & (p - 1)) == 0) && p > 0 ? "YES" : "NO");
    
    printf("\nExplanation for Power of 2:\n");
    printf("8 & 7 = 1000 & 0111 = 0000 = 0 ✓ (Power of 2)\n");
    printf("7 & 6 = 0111 & 0110 = 0110 ≠ 0 ✗ (Not Power of 2)\n");
    
    return 0;
}
```

---

### 1.5 ASSIGNMENT OPERATORS

#### Theory
Assignment operators assign and optionally perform an operation.

| Operator | Equivalent |
|----------|------------|
| a = 5 | Direct assignment |
| a += 5 | a = a + 5 |
| a -= 5 | a = a - 5 |
| a *= 5 | a = a * 5 |
| a /= 5 | a = a / 5 |
| a &= 5 | a = a & 5 |

#### Program: Assignment Operators
```c
#include <stdio.h>

int main()
{
    printf("----------ASSIGNMENT OPERATORS----------\n");
    
    int p = 10, q = 8;
    printf("Initial: p = %d, q = %d\n", p, q);
    
    // Bitwise AND assignment
    p &= q;
    printf("After p &= q: p = %d\n", p);  // 8
    
    // Output of assignment operator
    int k = 5;
    printf("Result of (k = 10): %d\n", k = 10);  // 10
    
    return 0;
}
```

---

### 1.6 TERNARY/CONDITIONAL OPERATOR

#### Theory
The ternary operator provides a shorthand for if-else: `condition ? expression_if_true : expression_if_false`

#### Diagram: Ternary Operator Flow
```
Condition?   Expression1   :   Expression2
    ↓             ↓             ↓
  True        Execute1      Execute2
   ↓                          ↓
Return1               Return2
   ↓________________________↓
          Result
```

#### Program: Ternary Operator
```c
#include <stdio.h>

int main()
{
    printf("----------TERNARY OPERATOR----------\n");
    
    int o = 7;
    printf("%d is %s\n", o, (o % 2 == 0) ? "Even" : "Odd");
    
    int r = 8;
    printf("(8 > 5) ? (8 < 10) : 0 = %d\n", (r > 5) ? (r < 10) : 0);
    // 8 > 5 is true, so evaluate (8 < 10) which is true (1)
    
    return 0;
}
```

---

## IF-ELSE STATEMENTS

### 2.1 SIMPLE IF-ELSE

#### Theory
The if-else statement executes one block if condition is true, another if false.

#### Syntax
```c
if (condition)
{
    // Block 1: executed if condition is true
}
else
{
    // Block 2: executed if condition is false
}
```

#### Program: Check 3-Digit Palindrome
```c
#include <stdio.h>

int main()
{
    int n;
    printf("Enter a 3-digit number: ");
    scanf("%d", &n);
    
    // Extract first and last digits
    // First digit: n / 100
    // Last digit: n % 10
    
    if (n / 100 == n % 10)
        printf("%d is a Palindrome\n", n);
    else
        printf("%d is NOT a Palindrome\n", n);
    
    return 0;
}
```

#### Step-wise Explanation
**Example: n = 121**
1. First digit = 121 / 100 = 1
2. Last digit = 121 % 10 = 1
3. 1 == 1 → TRUE → "Palindrome"

**Example: n = 123**
1. First digit = 123 / 100 = 1
2. Last digit = 123 % 10 = 3
3. 1 == 3 → FALSE → "NOT a Palindrome"

---

### 2.2 CHECK CONSONANT

#### Program: Character Type Checker
```c
#include <stdio.h>

int main()
{
    char ch;
    printf("Enter a character: ");
    scanf(" %c", &ch);
    
    // Check if it's a letter AND not a vowel
    if (((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) &&
        !(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
          ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'))
        printf("%c is a Consonant\n", ch);
    else
        printf("%c is NOT a consonant\n", ch);
    
    return 0;
}
```

#### Diagram: Logic Flow
```
Input Character
    ↓
Is it a Letter? (A-Z or a-z)
    ↓ YES    ↓ NO
    |        → NOT Consonant
    ↓
Is it NOT a Vowel? (not a,e,i,o,u)
    ↓ YES    ↓ NO
    |        → NOT Consonant (it's a vowel)
    ↓
CONSONANT
```

---

### 2.3 CHECK MIDDLE DIGIT IS LARGEST

#### Program: 3-Digit Analysis
```c
#include <stdio.h>

int main()
{
    int n;
    printf("Enter a 3-digit number: ");
    scanf("%d", &n);
    
    // Extract digits from 572
    // First digit: 572 / 100 = 5
    // Middle digit: (572 / 10) % 10 = 57 % 10 = 7
    // Last digit: 572 % 10 = 2
    
    if ((n / 10) % 10 > n / 100 && (n / 10) % 10 > n % 10)
        printf("Middle digit is LARGEST\n");
    else
        printf("Condition NOT satisfied\n");
    
    return 0;
}
```

#### Step-wise Explanation for 572
```
Step 1: Extract digits
  First digit = 572 / 100 = 5
  Middle digit = (572 / 10) % 10 = 57 % 10 = 7
  Last digit = 572 % 10 = 2

Step 2: Check condition
  Is 7 > 5? YES
  Is 7 > 2? YES
  
Result: Middle digit is LARGEST ✓
```

---

### 2.4 CHECK PRODUCT OF DIGITS IS ODD

#### Program: Digit Product Analysis
```c
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    
    // For 357: product = 3 * 5 * 7 = 105 (odd)
    // Extract and multiply: (n/100) * ((n/10)%10) * (n%10)
    
    if ((n / 100 * (n / 10) % 10 * n % 10) % 2 != 0)
        printf("Product of digits is ODD\n");
    else
        printf("Product of digits is EVEN\n");
    
    return 0;
}
```

---

### 2.5 CHECK 3-DIGIT WITH NON-IDENTICAL DIGITS

#### Program: 3-Digit Non-Identical Check
```c
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    
    // Check: 100 ≤ n ≤ 999 AND NOT all digits same
    if (n >= 100 && n <= 999 &&
        !(n / 100 == (n / 10) % 10 && (n / 10) % 10 == n % 10))
        printf("3-digit and digits are NOT all the same\n");
    else
        printf("Condition NOT satisfied\n");
    
    return 0;
}
```

#### Diagram: Digit Extraction and Comparison
```
For number 357:
  First digit = 357 / 100 = 3
  Middle digit = (357 / 10) % 10 = 35 % 10 = 5
  Last digit = 357 % 10 = 7

Check: 3 == 5 && 5 == 7? NO → "Digits NOT all same"

For number 555:
  First digit = 555 / 100 = 5
  Middle digit = (555 / 10) % 10 = 55 % 10 = 5
  Last digit = 555 % 10 = 5

Check: 5 == 5 && 5 == 5? YES → Apply NOT operator
Result: NOT YES = "All digits same" (condition failed)
```

---

### 2.6 ARMSTRONG NUMBER

#### Theory
An Armstrong number (narcissistic number) is a number that equals the sum of its digits each raised to the power of the number of digits.

For 3-digit numbers: n = d1³ + d2³ + d3³

Examples:
- 153 = 1³ + 5³ + 3³ = 1 + 125 + 27 = 153 ✓
- 370 = 3³ + 7³ + 0³ = 27 + 343 + 0 = 370 ✓

#### Program: Armstrong Number Checker
```c
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    
    // Extract digits and calculate sum of cubes
    int sum = (n / 100) * (n / 100) * (n / 100) +
              ((n / 10) % 10) * ((n / 10) % 10) * ((n / 10) % 10) +
              (n % 10) * (n % 10) * (n % 10);
    
    if (sum == n)
        printf("%d is an Armstrong number\n", n);
    else
        printf("%d is NOT an Armstrong number\n", n);
    
    return 0;
}
```

#### Step-wise Explanation for 153
```
Step 1: Extract digits
  d1 = 153 / 100 = 1
  d2 = (153 / 10) % 10 = 15 % 10 = 5
  d3 = 153 % 10 = 3

Step 2: Calculate sum of cubes
  1³ = 1 * 1 * 1 = 1
  5³ = 5 * 5 * 5 = 125
  3³ = 3 * 3 * 3 = 27
  Sum = 1 + 125 + 27 = 153

Step 3: Compare
  153 == 153? YES ✓ Armstrong number
```

---

## ELSE-IF LADDER

### 3.1 MARKS CLASSIFICATION

#### Theory
The else-if ladder allows checking multiple conditions in sequence. Once a condition is true, its block executes and remaining conditions are skipped.

#### Important Caveat
The order of conditions matters! A less restrictive condition before a more restrictive one will never execute the later condition.

#### Program: Marks Classification - WRONG ORDER
```c
#include <stdio.h>

int main()
{
    int n = 75;
    
    if (n >= 50)
        printf("Pass");  // This executes even for Distinction!
    else if (n >= 75)
        printf("Distinction");  // This NEVER executes
    else
        printf("Fail");
    
    return 0;
}
```

#### Diagram: Wrong Order Execution
```
n = 75

Condition 1: n >= 50?
  YES → Execute "Pass" and exit
  
Condition 2: n >= 75? (NEVER REACHED!)
  Not checked because condition 1 was true
```

#### Program: Marks Classification - CORRECT ORDER
```c
#include <stdio.h>

int main()
{
    int n = 75;
    
    if (n >= 75 && n <= 100)
        printf("Distinction");
    else if (n >= 50 && n < 75)
        printf("Pass");
    else
        printf("Fail");
    
    return 0;
}
```

#### Diagram: Correct Order Execution
```
n = 75

Condition 1: 75 >= 75 && 75 <= 100?
  YES → Execute "Distinction" and exit ✓

(If condition 1 false)
Condition 2: n >= 50 && n < 75?
  Check only if condition 1 is false
  
(If condition 2 false)
Condition 3: else
  Default fallback
```

---

### 3.2 LARGEST OF 3 NUMBERS

#### Program: Find Maximum
```c
#include <stdio.h>

int main()
{
    int a, b, c;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);
    
    if (a >= b && a >= c)
        printf("A is largest\n");
    else if (b >= a && b >= c)
        printf("B is largest\n");
    else
        printf("C is largest\n");
    
    return 0;
}
```

#### Step-wise Execution for a=10, b=20, c=15
```
Check 1: 10 >= 20 && 10 >= 15?
  10 >= 20 is FALSE
  Result: FALSE → Skip this block

Check 2: 20 >= 10 && 20 >= 15?
  20 >= 10 is TRUE
  20 >= 15 is TRUE
  Result: TRUE → Execute "B is largest" ✓
```

---

### 3.3 TRIANGLE TYPE CLASSIFICATION

#### Theory
Triangle Validity Rule: Sum of any two sides must be greater than the third side.
- If a + b ≤ c OR b + c ≤ a OR a + c ≤ b → NOT a triangle
- If all sides equal (a == b == c) → Equilateral
- If exactly two sides equal → Isosceles
- If all sides different → Scalene

#### Program: Triangle Classifier
```c
#include <stdio.h>

int main()
{
    int a, b, c;
    printf("Enter three sides: ");
    scanf("%d %d %d", &a, &b, &c);
    
    // Check triangle validity first
    if (a + b <= c || b + c <= a || a + c <= b)
        printf("Not a triangle\n");
    
    // All sides equal
    else if (a == b && b == c)
        printf("Equilateral triangle\n");
    
    // Any two sides equal
    else if (a == b || b == c || a == c)
        printf("Isosceles triangle\n");
    
    // All sides different
    else
        printf("Scalene triangle\n");
    
    return 0;
}
```

#### Diagram: Triangle Classification Flow
```
Input: a, b, c

Validity Check:
a+b > c AND b+c > a AND a+c > b ?
  ↓ NO            ↓ YES
  NOT a         Check type:
  triangle        ↓
              a==b && b==c?
                ↓ YES        ↓ NO
              EQUILATERAL   a==b OR b==c OR a==c?
                              ↓ YES         ↓ NO
                            ISOSCELES     SCALENE
```

#### Step-wise Verification for 3, 4, 5
```
Input: a=3, b=4, c=5

Validity Check:
  3 + 4 > 5? YES (7 > 5)
  4 + 5 > 3? YES (9 > 3)
  3 + 5 > 4? YES (8 > 4)
  Result: VALID triangle

Type Check:
  3 == 4 && 4 == 5? NO
  3 == 4 OR 4 == 5 OR 3 == 5? NO
  Result: SCALENE triangle
```

---

### 3.4 BITWISE ODD/EVEN CHECK

#### Theory
The least significant bit (LSB) determines if a number is odd or even:
- If LSB = 1 → Odd
- If LSB = 0 → Even

Using bitwise AND: `if (n & 1)` checks if LSB is 1

#### Program: Bitwise Odd/Even Check
```c
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    
    if (n & 1)
        printf("Odd\n");
    else if (!(n & 1))
        printf("Even\n");
    else
        printf("Impossible\n");  // This block never executes
    
    return 0;
}
```

#### Diagram: Bitwise AND with 1
```
Odd number (7):
  7 in binary: ...0111
  1 in binary: ...0001
  7 & 1:       ...0001 = 1 (TRUE - Odd)

Even number (8):
  8 in binary: ...1000
  1 in binary: ...0001
  8 & 1:       ...0000 = 0 (FALSE - Even)
```

---

### 3.5 CHECK IF POWER OF 2

#### Theory
A number is a power of 2 if it has exactly ONE bit set in binary.

Using bitwise trick: `(n & (n-1)) == 0` returns true for powers of 2

#### Diagram: Power of 2 Logic
```
8 (Power of 2):
  8  in binary: 1000
  7  in binary: 0111
  -----------
  8 & 7 =      0000 = 0 ✓ (Power of 2)

7 (NOT Power of 2):
  7  in binary: 0111
  6  in binary: 0110
  -----------
  7 & 6 =      0110 ≠ 0 ✗ (Not Power of 2)
```

#### Program: Power of 2 Checker
```c
#include <stdio.h>

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    
    if (n <= 0)
        printf("Invalid\n");
    else if ((n & (n - 1)) == 0)
        printf("%d is Power of 2\n", n);
    else
        printf("%d is NOT Power of 2\n", n);
    
    return 0;
}
```

#### Step-wise Explanation for 16
```
Step 1: Check if positive
  16 > 0? YES ✓

Step 2: Apply bitwise check
  16 & 15 == 0?
  16 in binary: 10000
  15 in binary: 01111
  ---------------
  16 & 15:      00000 = 0 ✓
  
Result: 16 is Power of 2
```

---

### 3.6 REVERSE A 3-DIGIT NUMBER

#### Program: 3-Digit Reversal
```c
#include <stdio.h>

int main()
{
    int n, reverse;
    printf("Enter a 3-digit number: ");
    scanf("%d", &n);
    
    if (n < 100 || n > 999)
        printf("Invalid input\n");
    else if (n >= 100 && n <= 999)
    {
        int hundreds = n / 100;
        int tens = (n / 10) % 10;
        int units = n % 10;
        
        reverse = units * 100 + tens * 10 + hundreds;
        
        printf("Reversed number = %d\n", reverse);
    }
    else
        printf("Error\n");
    
    return 0;
}
```

#### Step-wise Reversal for 456
```
Step 1: Extract digits
  hundreds = 456 / 100 = 4
  tens = (456 / 10) % 10 = 45 % 10 = 5
  units = 456 % 10 = 6

Step 2: Rearrange
  reverse = 6*100 + 5*10 + 4
  reverse = 600 + 50 + 4 = 654

Result: 456 reversed is 654
```

---

## LOGICAL OPERATORS

### 4.1 LOGICAL AND (&&)

#### Theory
- `a && b` returns 1 (true) if BOTH a and b are true
- Returns 0 (false) otherwise
- **Short Circuit**: If a is false, b is NOT evaluated

#### Program: AND with Short Circuit
```c
#include <stdio.h>

int main()
{
    int a = 0, b = 5;
    
    if (a && b++)
        printf("Inside if block\n");
    
    printf("b = %d\n", b);  // b = 5 (NOT incremented!)
    
    return 0;
}
```

#### Diagram: Short Circuit AND
```
a && b++

a = 0 (FALSE)?
  ↓ YES
  Don't evaluate b++
  b remains 5
  
  ↓ NO
  Evaluate b++
  b increments
```

#### Explanation
Since `a = 0` is false, the entire AND expression is false without checking `b++`. Therefore, `b` is never incremented and remains 5.

---

### 4.2 LOGICAL OR (||)

#### Theory
- `a || b` returns 1 (true) if AT LEAST ONE of a or b is true
- Returns 0 (false) only if both are false
- **Short Circuit**: If a is true, b is NOT evaluated

#### Program: OR with Short Circuit
```c
#include <stdio.h>

int main()
{
    int a = 5, b = 0;
    
    if (a || b++)
        printf("b = %d\n", b);  // b = 0 (NOT incremented!)
    
    return 0;
}
```

#### Diagram: Short Circuit OR
```
a || b++

a = 5 (TRUE)?
  ↓ YES
  Don't evaluate b++
  b remains 0
  
  ↓ NO
  Evaluate b++
  b increments
```

---

### 4.3 LOGICAL NOT (!)

#### Theory
- `!a` returns 1 (true) if a is 0 (false)
- Returns 0 (false) if a is non-zero (true)

#### Program: NOT Operator
```c
#include <stdio.h>

int main()
{
    printf("!0 = %d\n", !0);      // 1
    printf("!5 = %d\n", !5);      // 0
    printf("!(-3) = %d\n", !(-3)); // 0
    
    int x = 0;
    if (!x)
        printf("x is FALSE/0\n");
    
    return 0;
}
```

---

### 4.4 LEAP YEAR CHECK

#### Theory
A year is a leap year if:
- (Divisible by 4 AND NOT divisible by 100) OR (Divisible by 400)

Formula: `(y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)`

#### Program: Leap Year Checker
```c
#include <stdio.h>

int main()
{
    int y;
    printf("Enter year: ");
    scanf("%d", &y);
    
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
        printf("%d is a Leap Year\n", y);
    else
        printf("%d is NOT a Leap Year\n", y);
    
    return 0;
}
```

#### Diagram: Leap Year Logic
```
Year = 2000

Check 1: (2000 % 4 == 0) && (2000 % 100 != 0)?
  2000 % 4 = 0 ✓
  2000 % 100 = 0 (not != 0) ✗
  Result: FALSE

Check 2: 2000 % 400 == 0?
  2000 % 400 = 0 ✓
  Result: TRUE

Overall: FALSE || TRUE = TRUE → LEAP YEAR ✓

---

Year = 1900

Check 1: (1900 % 4 == 0) && (1900 % 100 != 0)?
  1900 % 4 = 0 ✓
  1900 % 100 = 0 (not != 0) ✗
  Result: FALSE

Check 2: 1900 % 400 == 0?
  1900 % 400 = 300 ✗
  Result: FALSE

Overall: FALSE || FALSE = FALSE → NOT LEAP YEAR ✓
```

#### Step-wise for 2024
```
Step 1: Check divisible by 4
  2024 % 4 = 0? YES

Step 2: Check NOT divisible by 100
  2024 % 100 = 24? YES (24 ≠ 0)

Step 3: (YES && YES) = TRUE
  
Result: 2024 is a LEAP YEAR
```

---

### 4.5 TRIANGLE VALIDITY

#### Program: Triangle Validity Check
```c
#include <stdio.h>

int main()
{
    int a, b, c;
    printf("Enter 3 sides: ");
    scanf("%d %d %d", &a, &b, &c);
    
    if (a + b > c && b + c > a && a + c > b)
        printf("Valid triangle\n");
    else
        printf("Invalid triangle\n");
    
    return 0;
}
```

---

### 4.6 LOGICAL RETURN VALUES

#### Theory
Logical operators return 1 for true and 0 for false.

#### Program: Logical Return Values
```c
#include <stdio.h>

int main()
{
    printf("5 && 2 = %d\n", 5 && 2);      // 1 (both non-zero)
    printf("5 || 0 = %d\n", 5 || 0);      // 1 (at least one non-zero)
    printf("!5 = %d\n", !5);              // 0 (5 is true, NOT true = false)
    printf("!0 = %d\n", !0);              // 1 (0 is false, NOT false = true)
    
    return 0;
}
```

---

## BITWISE OPERATORS (DETAILED)

### 5.1 BITWISE NEGATION

#### Theory
`~n = -(n + 1)` [shortcut formula]

For n = -2:
```
-2 in 2's complement (32-bit):
  Step 1: Positive binary of 2
          00000000 00000000 00000000 00000010
  Step 2: Flip all bits
          11111111 11111111 11111111 11111101
  Step 3: Add 1
          11111111 11111111 11111111 11111110
          
~(-2):
  Flip all bits of 11111111 11111111 11111111 11111110
         00000000 00000000 00000000 00000001 = 1
```

#### Program: Bitwise Negation
```c
#include <stdio.h>

int main()
{
    int a = -2;
    printf("~(-2) = %d\n", ~a);  // 1
    
    // Using shortcut formula
    // ~n = -(n + 1)
    printf("~(-2) = -((-2) + 1) = -(-1) = 1\n");
    
    return 0;
}
```

---

## SWITCH STATEMENT

### 6.1 BASIC SWITCH

#### Theory
Switch statement selects one of many code blocks to execute based on an expression value.

#### Syntax
```c
switch(expression)
{
    case value1:
        // code if expression == value1
        break;
    case value2:
        // code if expression == value2
        break;
    default:
        // code if no case matches
}
```

#### Important: Break Statement
- `break;` exits the switch
- Without `break;`, execution "falls through" to the next case

#### Program: Vowel Checker with Multiple Cases
```c
#include <stdio.h>

int main()
{
    char ch;
    printf("Enter a character: ");
    scanf(" %c", &ch);
    
    switch (ch) {
        case 'a': case 'e': case 'i': case 'o': case 'u':
        case 'A': case 'E': case 'I': case 'O': case 'U':
            printf("%c is a Vowel\n", ch);
            break;
        default:
            printf("%c is NOT a vowel\n", ch);
    }
    
    return 0;
}
```

#### Diagram: Switch Execution Flow
```
Input: ch = 'e'

Evaluate: ch
Compare with cases:
  'a'? NO
  'e'? YES → Execute block → Print "Vowel" → break;
  (skip remaining cases due to break)
  
Output: e is a Vowel
```

---

### 6.2 CALCULATOR USING SWITCH

#### Program: Simple Calculator
```c
#include <stdio.h>

int main()
{
    int a, b;
    char op;
    
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    
    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &op);   // Space before %c is important
    
    switch(op) {
        case '+':
            printf("Result = %d\n", a + b);
            break;
        case '-':
            printf("Result = %d\n", a - b);
            break;
        case '*':
            printf("Result = %d\n", a * b);
            break;
        case '/':
            if (b != 0)
                printf("Result = %d\n", a / b);
            else
                printf("Division by zero not allowed\n");
            break;
        default:
            printf("Invalid operator\n");
    }
    
    return 0;
}
```

---

### 6.3 FALL THROUGH BEHAVIOR

#### Theory
When a `break;` is missing, execution continues to the next case (fall through).

#### Program: Character to ASCII
```c
#include <stdio.h>

int main()
{
    char ch = 'B';   // ASCII value of 'B' is 66
    
    switch(ch) {
        case 65:
            printf("A\n");
            break;
        case 66:
            printf("B\n");
            break;
        default:
            printf("Other\n");
            break;
    }
    
    return 0;
}
```

#### Step-wise Execution
```
ch = 'B' (ASCII value = 66)

Switch evaluates: ch
  case 65? (Is 'B' == 65?) NO
  case 66? (Is 'B' == 66?) YES
    → Execute: printf("B\n")
    → break; → Exit switch

Output: B
```

---

## PRECEDENCE AND ASSOCIATIVITY

### 7.1 OPERATOR PRECEDENCE

#### Theory
Precedence determines which operator is evaluated first when multiple operators are present.

#### Precedence Table (High to Low)
```
1. () [] . -> :: (Parentheses, brackets, member access)
2. ++ -- + - ! ~ (Unary operators, increment/decrement)
3. * / % (Multiplication, division, modulus)
4. + - (Addition, subtraction)
5. << >> (Bitwise shifts)
6. < <= > >= (Relational operators)
7. == != (Equality)
8. & (Bitwise AND)
9. ^ (Bitwise XOR)
10. | (Bitwise OR)
11. && (Logical AND)
12. || (Logical OR)
13. ?: (Ternary)
14. = += -= *= /= %= &= |= ^= <<= >>= (Assignment)
```

#### Program: Precedence Examples
```c
#include <stdio.h>

int main()
{
    printf("----------PRECEDENCE EXAMPLES----------\n");
    
    // * has higher precedence than +
    int x = 10 + 5 * 2;
    printf("10 + 5 * 2 = %d (10 + (5*2) = 10 + 10 = 20)\n", x);
    
    // Parentheses override precedence
    int y = (10 + 5) * 2;
    printf("(10 + 5) * 2 = %d (15 * 2 = 30)\n", y);
    
    // / and * same precedence, left to right
    int z = 20 / 5 * 2;
    printf("20 / 5 * 2 = %d ((20/5)*2 = 4*2 = 8)\n", z);
    
    // NOT chained relational
    printf("100 > 25 > 1 = %d ((100>25)>1 = 1>1 = 0)\n", 100 > 25 > 1);
    
    return 0;
}
```

---

### 7.2 ASSOCIATIVITY

#### Theory
When operators have the same precedence, associativity determines the order of evaluation.

- **Left-to-right**: Evaluated from left to right (e.g., 20 / 5 * 2 = (20/5)*2 = 8)
- **Right-to-left**: Evaluated from right to left (e.g., a = b = c assigns c to b, then b to a)

#### Program: Associativity Examples
```c
#include <stdio.h>

int main()
{
    printf("----------ASSOCIATIVITY EXAMPLES----------\n");
    
    // Left-to-right: * and / same precedence
    int z = 20 / 5 * 2;
    printf("20 / 5 * 2 = %d ((20/5)*2 = 4*2 = 8)\n", z);
    
    // Right-to-left: Assignment operators
    int a, b, c;
    a = b = c = 5;
    printf("a = b = c = 5 → a=%d, b=%d, c=%d\n", a, b, c);
    
    // Right-to-left: Unary operators
    int d = 5;
    int e = ++d + 3;
    printf("++d + 3: d=%d, e=%d (d becomes 6, e = 6+3 = 9)\n", d, e);
    
    return 0;
}
```

#### Diagram: Assignment Right-to-Left
```
a = b = c = 5

Evaluation (right-to-left):
  Step 1: c = 5 (c gets 5)
  Step 2: b = (result of c=5) → b = 5
  Step 3: a = (result of b=5) → a = 5
  
Final: a=5, b=5, c=5
```

---

## SEQUENCE POINTS

### 8.1 UNDEFINED BEHAVIOR WITHOUT SEQUENCE POINTS

#### Theory
A sequence point is a point in code where all previous side effects must be complete before moving forward. Without sequence points between modifications, behavior is undefined.

#### Program: Undefined Behavior
```c
#include <stdio.h>

int main()
{
    int i = 5;
    int x;
    
    // UNDEFINED BEHAVIOR: i is modified twice without a sequence point
    x = i++ + ++i;  // + operator is NOT a sequence point
    
    printf("i = %d\n", i);
    printf("x = %d\n", x);
    
    // Different compilers may give different results!
    
    return 0;
}
```

#### Why It's Undefined
```
x = i++ + ++i

Multiple interpretations possible:
1. i++ (use 5, increment to 6) + ++i (increment to 7, use 7)
   → 5 + 7 = 12, i = 7

2. ++i (increment to 6, use 6) + i++ (use 6, increment to 7)
   → 6 + 6 = 12, i = 7

3. Other orders based on compiler optimizations
   
The C standard does NOT define the order of evaluation
for operators that are NOT sequence points.
```

---

### 8.2 USING SEQUENCE POINTS

#### Theory
Common sequence points:
- `;` (semicolon - end of statement)
- `,` (comma operator)
- `&&` (logical AND)
- `||` (logical OR)
- `?:` (ternary operator)

#### Program: Safe Evaluation with Sequence Points
```c
#include <stdio.h>

int main()
{
    int i = 5;
    
    // SAFE: Use intermediate variables with sequence points (;)
    i++;                // Side effect 1: i becomes 6
    int temp = ++i;     // Side effect 2: i becomes 7, temp = 7
    
    int x = (i - 1) + temp;  // (7 - 1) + 7 = 13
    printf("i = %d\n", i);
    printf("temp = %d\n", temp);
    printf("x = %d\n", x);
    
    return 0;
}
```

#### Output
```
i = 7
temp = 7
x = 13
```

---

### 8.3 LOGICAL OPERATORS AS SEQUENCE POINTS

#### Program: AND as Sequence Point
```c
#include <stdio.h>

int main()
{
    int i = 0;
    
    // && is a sequence point
    // Left operand (i != 0) must complete before right operand (i++)
    (i != 0) && (i++);
    
    printf("i = %d\n", i);  // 0
    // i++ is NOT evaluated because (i != 0) is false
    
    return 0;
}
```

---

### 8.4 TERNARY OPERATOR AS SEQUENCE POINT

#### Program: Ternary as Sequence Point
```c
#include <stdio.h>

int main()
{
    int i = 5;
    int x;
    
    // Ternary operator is a sequence point
    x = (i > 0) ? i++ : --i;
    
    printf("x = %d\n", i);      // 5 (i > 0 is true, so use i++ - current value)
    printf("i = %d\n", i);      // 6 (i incremented after assignment)
    
    return 0;
}
```

---

### 8.5 OR OPERATOR AS SEQUENCE POINT

#### Program: OR as Sequence Point
```c
#include <stdio.h>

int main()
{
    int a = 0, b = 0;
    
    // || is a sequence point
    // Left operand must complete before right operand
    if ((a = 5) || (b = 10))
        printf("a=%d, b=%d\n", a, b);
    
    // Output: a=5, b=0
    // Reason: a=5 is true, so b=10 is NOT evaluated (short circuit)
    
    return 0;
}
```

---

## COMPREHENSIVE SUMMARY TABLE

| Topic | Key Concept | Example |
|-------|-------------|---------|
| **Operators** | Arithmetic: +, -, *, /, % | 5 + 3 = 8 |
| | Integer division truncates | 5 / 2 = 2 |
| | Type casting priority | (float)5/2 = 2.5 |
| **Increment** | Pre: ++a (modify first) | ++a is different from a++ |
| | Post: a++ (use first) | in expressions |
| **Bitwise** | AND: & | 10 & 8 = 8 |
| | OR: \| | 10 \| 8 = 10 |
| | NOT: ~ | ~10 = -11 |
| | Shift: <<, >> | 10 << 2 = 40 |
| **Odd/Even** | Use n & 1 | (n & 1) → 1 if odd |
| **Power of 2** | Use (n & (n-1)) == 0 | 8 & 7 = 0 ✓ |
| **If-Else** | Order matters in else-if | Check restrictive conditions first |
| **Logical** | Short circuit: && and \|\| | if (a && b++) - b++ not evaluated if a false |
| **Switch** | Use break to prevent fall through | Missing break causes fall through |
| **Precedence** | * / % before + - | 2 + 3 * 4 = 14 |
| **Associativity** | Most left-to-right | 20 / 5 * 2 = 8 |
| | Assignment right-to-left | a = b = 5 assigns 5 to both |
| **Sequence Points** | Avoid modifying variable twice | Use intermediate variables |
| | without sequence point | between modifications |

---

## BEST PRACTICES

1. **Always check order in else-if ladders**: Place more restrictive conditions first
2. **Use parentheses for clarity**: Don't rely on precedence when complex
3. **Avoid undefined behavior**: Use sequence points when modifying variables
4. **Be careful with bitwise operations**: Remember they work on bit level
5. **Use break in switch statements**: Prevent unintended fall through
6. **Test edge cases**: Especially for digit extraction and mathematical operations
7. **Understand short circuit evaluation**: Useful for avoiding unnecessary computations
8. **Cast types explicitly**: Avoid relying on implicit type conversion

---

## PRACTICE PROBLEMS

### Problem 1: Age Classification
Write a program to classify age into: Child (0-12), Teen (13-19), Adult (20-59), Senior (60+)

### Problem 2: Grade Calculator
Convert marks (0-100) to grades: A (90-100), B (80-89), C (70-79), D (60-69), F (<60)

### Problem 3: Number Properties
Check if a number is: Positive, Negative, or Zero; and Odd or Even

### Problem 4: Digit Sum
Calculate the sum of digits of a 4-digit number and check if it's odd/even

### Problem 5: Perfect Number
A perfect number equals the sum of its divisors. Example: 6 = 1+2+3. Check if a number is perfect.

---

**Document Version**: 1.0  
**Last Updated**: June 10, 2026  
**Compiled by**: Pragun-07
