# C Programming Language - Complete Guide with Code Examples & Diagrams

**Author:** Prof. Sonali Kalekar  
**Student Notes:** Pragun-07  
**Date:** June 2026  
**Version:** 1.0

---

## Table of Contents

1. [Introduction to C](#introduction)
2. [C Tokens & Identifiers](#tokens-identifiers)
3. [Keywords & Reserved Words](#keywords)
4. [Variables - Declaration, Definition & Initialization](#variables)
5. [Data Types](#data-types)
6. [Type Qualifiers](#type-qualifiers)
7. [Program Structure](#program-structure)
8. [Compilation Process](#compilation-process)
9. [Error Types & Warnings](#errors-warnings)
10. [Input/Output Functions](#input-output)
11. [Formatted Output - printf()](#printf)
12. [Formatted Input - scanf()](#scanf)
13. [Unformatted I/O Functions](#unformatted-io)
14. [Features & Applications](#features)
15. [Complete Working Examples](#examples)

---

## <a name="introduction"></a>Chapter 1: Introduction to C

### What is C?

C is a **general-purpose, procedural, high-level programming language** created by **Dennis Ritchie** in 1972.

**Key Characteristics:**
- Combines high-level and low-level language features
- Procedural programming paradigm
- Simple, efficient, and powerful
- Foundation for modern programming

### Why Learn C?

```
Benefits of Learning C:
┌─────────────────────────────────────┐
│ • Foundation Language               │
│ • Gateway to other languages        │
│ • Widely used in industry           │
│ • Fast execution                    │
│ • Direct hardware access            │
│ • Portable across systems           │
│ • Small resource consumption        │
└─────────────────────────────────────┘
```

---

## <a name="tokens-identifiers"></a>Chapter 2: C Tokens & Identifiers

### What are Tokens?

A **token** is the smallest meaningful unit in a C program.

**Example: Token Breakdown**

```c
printf("HelloFriends");
```

Tokens are:
- `printf` → Identifier
- `(` → Special symbol
- `"HelloFriends"` → String constant
- `)` → Special symbol
- `;` → Special symbol

### Identifiers

An **identifier** is a name used for variables, functions, arrays, etc.

**Rules for Valid Identifiers:**

```
Valid:                  Invalid:
✓ student1              ✗ 1student (starts with digit)
✓ _myVar                ✗ my-var (contains hyphen)
✓ Student_123           ✗ my var (contains space)
✓ _mydocument           ✗ my@value (contains @)
✓ MAX_SIZE              ✗ my#var (contains #)
```

**Key Points:**
1. Starts with letter (a-z, A-Z) or underscore (_)
2. Followed by letters, digits, or underscore
3. Cannot contain punctuation (#, @, %)
4. Case-sensitive: `myFile ≠ myfile`
5. Cannot be a keyword
6. Maximum 31 characters recommended

---

## <a name="keywords"></a>Chapter 3: Keywords & Reserved Words

### The 32 C Keywords

```
auto      const     double    float     int       short     struct    unsigned
break     continue  else      for       long      signed    switch    void
case      default   enum      goto      register  sizeof    typedef   volatile
char      do        if        extern    return    static    union     while
```

**Keyword Categories:**

| Category | Keywords |
|----------|----------|
| **Data Types** | int, float, double, char, void |
| **Storage Classes** | auto, register, static, extern |
| **Control Flow** | if, else, switch, case, default |
| **Loops** | for, while, do |
| **Jump Statements** | break, continue, goto, return |
| **Type Modifiers** | const, volatile, signed, unsigned |
| **Derived Types** | struct, union, enum |
| **Other** | sizeof, typedef |

**Important:** Keywords cannot be used as variable or function names.

---

## <a name="variables"></a>Chapter 4: Variables - Declaration, Definition & Initialization

### What is a Variable?

A **variable** is a named storage location in memory that holds a value.

### 6 Characteristics of Variables

```
┌─────────────────────────────────────┐
│ 1. Name (Identifier)                │
│    Example: int myvalue_123         │
├─────────────────────────────────────┤
│ 2. Location (Memory Address)        │
│    Example: 0x7ffc6db6e44c          │
├─────────────────────────────────────┤
│ 3. Type (Data Type)                 │
│    Example: int, float, char        │
├─────────────────────────────────────┤
│ 4. Value (Data Stored)              │
│    Example: 10, 3.14, 'A'           │
├─────────────────────────────────────┤
│ 5. Lifetime (Duration in Memory)    │
│    Example: Local, Global           │
├─────────────────────────────────────┤
│ 6. Scope (Accessible Region)        │
│    Example: Inside function, global │
└─────────────────────────────────────┘
```

### 1. Name and Location

```c
#include <stdio.h>

int main() {
    int a = 10;
    printf("Variable name: a\n");
    printf("Variable value: %d\n", a);
    printf("Variable address: %p\n", &a);
    return 0;
}
```

**Output:**
```
Variable name: a
Variable value: 10
Variable address: 0x7ffc6db6e44c
```

### 2. Type

Specifies what kind of data and how much memory.

```c
int age = 25;              // 4 bytes, integer
float height = 5.9;        // 4 bytes, decimal
double salary = 50000.50;  // 8 bytes, decimal
char grade = 'A';          // 1 byte, character
```

### 3. Lifetime

Duration for which variable exists in memory.

```c
int global_var = 100;  // Global - exists for entire program

void function() {
    int local_var = 50;   // Local - exists only during function execution
    printf("%d\n", local_var);
}  // local_var destroyed here

int main() {
    function();
    printf("%d\n", global_var);  // Still exists
    return 0;
}
```

### 4. Scope

Region where variable is accessible.

```c
int global = 100;  // Global scope

void main() {
    int local = 50;   // Local scope (function)
    
    if (local > 10) {
        int block = 20;  // Block scope (if block)
        printf("%d %d %d\n", global, local, block);
    }
    // printf("%d", block);  // ERROR: out of scope
}
```

### Declaration, Definition, and Initialization

```c
extern int balance;        // Declaration (no memory allocated)
int balance;               // Definition (memory allocated)
int balance = 5000;        // Initialization (value assigned)
```

**Difference Table:**

| Term | Meaning | Example | Memory |
|------|---------|---------|--------|
| Declaration | Inform compiler | `extern int a;` | No |
| Definition | Allocate memory | `int a;` | Yes |
| Initialization | Assign value | `int a = 10;` | Yes |

### Why Use extern?

**Scenario: Bank Management System**

```c
// ===== account.c =====
int balance = 10000;  // Definition - actual storage

// ===== deposit.c =====
extern int balance;   // Declaration - refers to account.c's balance

void deposit(int amount) {
    balance += amount;
}

// ===== withdraw.c =====
extern int balance;   // Declaration - refers to account.c's balance

void withdraw(int amount) {
    balance -= amount;
}

// ===== main.c =====
extern int balance;   // Declaration

int main() {
    deposit(2000);     // balance = 12000
    withdraw(1500);    // balance = 10500
    printf("Final balance = %d", balance);
    return 0;
}
```

**Benefits:**
- Single memory location
- Efficient memory usage
- Prevents multiple definition errors
- Code modularity

---

## <a name="data-types"></a>Chapter 5: Data Types

### What are Data Types?

A data type specifies:
1. Kind of value a variable stores
2. Amount of memory allocated
3. Valid operations on values
4. Range of values allowed

### Classification

```
Data Types
    ├── Primary (Basic)
    │   ├── int
    │   ├── float
    │   ├── double
    │   ├── char
    │   └── void
    │
    ├── Derived
    │   ├── Array
    │   ├── Pointer
    │   └── Function
    │
    └── User-Defined
        ├── struct
        ├── union
        └── enum
```

### Primary Data Types

#### 1. int (Integer)

```c
int count = 100;
int negative = -50;
printf("Integer: %d\n", count);  // Output: Integer: 100
```

- **Size:** 4 bytes (typically)
- **Range:** -2,147,483,648 to 2,147,483,647 (32-bit)
- **Operations:** Arithmetic, comparison, logical

#### 2. float (Single Precision)

```c
float pi = 3.14;
float salary = 50000.50;
printf("Float: %.2f\n", pi);  // Output: Float: 3.14
```

- **Size:** 4 bytes
- **Precision:** ~6-7 decimal digits
- **Operations:** Decimal arithmetic

#### 3. double (Double Precision)

```c
double pi = 3.141592653589793;
double result = 123.456789123;
printf("Double: %.15lf\n", pi);
```

- **Size:** 8 bytes
- **Precision:** ~15-17 decimal digits
- **More accurate than float**

#### 4. char (Character)

```c
char grade = 'A';
char letter = 'Z';
char digit = '5';
printf("Char: %c\n", grade);  // Output: Char: A
```

- **Size:** 1 byte
- **Range:** -128 to 127 (signed), 0 to 255 (unsigned)
- **Stores:** ASCII character values

#### 5. void (No Type)

```c
void function();        // Function returns nothing
void *ptr;              // Generic pointer
```

**Uses:**
- Functions with no return value
- Generic pointers
- Function parameters

### Size of Data Types

```c
#include <stdio.h>

int main() {
    printf("Size of int: %zu bytes\n", sizeof(int));
    printf("Size of short: %zu bytes\n", sizeof(short));
    printf("Size of long: %zu bytes\n", sizeof(long));
    printf("Size of float: %zu bytes\n", sizeof(float));
    printf("Size of double: %zu bytes\n", sizeof(double));
    printf("Size of char: %zu bytes\n", sizeof(char));
    return 0;
}
```

**Typical Output:**
```
Size of int: 4 bytes
Size of short: 2 bytes
Size of long: 8 bytes
Size of float: 4 bytes
Size of double: 8 bytes
Size of char: 1 byte
```

**Memory Hierarchy:**

```
char .............. 1 byte
    ↓
short int ......... 2 bytes
    ↓
int ............... 4 bytes
    ↓
long int .......... 8 bytes
    ↓
float ............. 4 bytes
    ↓
double ............ 8 bytes
    ↓
long double ....... 16 bytes
```

### Data Type Ranges (limits.h)

```c
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    printf("Char range: %d to %d\n", CHAR_MIN, CHAR_MAX);
    printf("Int range: %d to %d\n", INT_MIN, INT_MAX);
    printf("Long range: %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("Float max: %g\n", FLT_MAX);
    printf("Double max: %g\n", DBL_MAX);
    return 0;
}
```

**Output:**
```
Char range: -128 to 127
Int range: -2147483648 to 2147483647
Long range: -9223372036854775808 to 9223372036854775807
Float max: 3.40282e+38
Double max: 1.79769e+308
```

### Number Systems in C

#### Decimal (Base 10)
```c
int decimal = 42;
```

#### Octal (Base 8) - Prefix: 0
```c
int octal = 0113;  // = 75 in decimal
printf("Octal 0113 = %d\n", octal);  // Output: 75
printf("Octal format: %o\n", octal);  // Output: 113
```

#### Hexadecimal (Base 16) - Prefix: 0x
```c
int hex = 0xA;     // = 10 in decimal
int hex2 = 0x1a;   // = 26 in decimal
printf("Hex 0xA = %d\n", hex);       // Output: 10
printf("Hex format: %x\n", hex);     // Output: a
printf("Hex format: %X\n", hex);     // Output: A
```

#### Binary (Base 2) - Prefix: 0b (GCC Extension)
```c
int binary = 0b111;  // = 7 in decimal
printf("Binary 0b111 = %d\n", binary);  // Output: 7
```

---

## <a name="type-qualifiers"></a>Chapter 6: Type Qualifiers

Type qualifiers modify variable behavior without changing data type.

### 1. const - Constant Qualifier

A `const` variable cannot be modified after initialization.

```c
#include <stdio.h>

int main() {
    const int height = 100;
    const float pi = 3.14;
    const char grade = 'A';
    
    printf("Height: %d\n", height);
    printf("Pi: %f\n", pi);
    printf("Grade: %c\n", grade);
    
    // height++;  // ERROR: cannot modify const
    // pi = 3.1415;  // ERROR: cannot modify const
    
    return 0;
}
```

**Use Cases:**
- Mathematical constants (PI, E)
- Configuration values
- Array sizes

### 2. volatile - Volatile Qualifier

Value may change unexpectedly from external sources.

```c
volatile int sensor_reading;  // Hardware register
volatile int signal;          // Can change from signal handler
```

### 3. static - Static Storage Class

Preserves variable value between function calls.

```c
#include <stdio.h>

void counter() {
    static int count = 0;  // Initialized only once
    count++;
    printf("Count: %d\n", count);
}

int main() {
    counter();  // Output: Count: 1
    counter();  // Output: Count: 2
    counter();  // Output: Count: 3
    return 0;
}
```

### 4. register - Register Storage Class

Suggests storing variable in CPU register for faster access.

```c
register int loop_counter;  // Request fast access
```

**Qualifier Summary:**

| Qualifier | Effect | Use Case |
|-----------|--------|----------|
| `const` | Value cannot change | Constants |
| `volatile` | Value may change unexpectedly | Hardware registers |
| `static` | Preserves value between calls | Counters, state |
| `register` | Store in CPU register | Performance |

---

## <a name="program-structure"></a>Chapter 7: Program Structure

### Standard C Program Structure

```c
/**********************************************
 * DOCUMENTATION SECTION
 * Program: Calculate Student Grade
 * Author: John Doe
 * Date: June 2026
 **********************************************/

// LINKING SECTION (Preprocessor Directives)
#include <stdio.h>
#include <math.h>

// DEFINITION SECTION (Optional)
#define MAX_STUDENTS 100
#define PASSING_MARK 40

// GLOBAL DECLARATION SECTION (Optional)
int total_students = 0;
float class_average = 0.0;

// FUNCTION DECLARATION (Optional)
void display_menu();
float calculate_percentage(int marks, int total);

// MAIN FUNCTION SECTION (Essential)
int main()
{
    /***** Declaration Part *****/
    int student_marks;
    float percentage;
    
    /***** Executable Part *****/
    student_marks = 85;
    percentage = calculate_percentage(student_marks, 100);
    
    printf("Marks: %d\n", student_marks);
    printf("Percentage: %.2f%%\n", percentage);
    
    display_menu();
    
    return 0;  // Successful execution
}

// SUB PROGRAM SECTION (Optional)
void display_menu() {
    printf("\n===== Menu =====\n");
    printf("1. Add Student\n");
    printf("2. View Grades\n");
}

float calculate_percentage(int marks, int total) {
    return (marks * 100.0) / total;
}
```

### Program Structure Sections Explained

#### 1. Documentation Section
```c
/**
 * Program: Bank Management System
 * Author: Prof. Sonali
 * Date: June 2026
 * Description: Manages customer accounts
 */
```

#### 2. Linking Section
```c
#include <stdio.h>    // Standard Input/Output
#include <math.h>     // Mathematical functions
#include <string.h>   // String functions
#include <stdlib.h>   // Standard library
```

#### 3. Definition Section
```c
#define PI 3.14159
#define MAX_SIZE 100
#define BUFFER_SIZE 256
```

#### 4. Global Declaration
```c
int global_counter = 0;
float global_sum = 0.0;
```

#### 5. Main Function
```c
int main() {
    // Variable declarations
    // Program logic
    return 0;
}
```

#### 6. Sub Program Section
```c
void add_student() { /* ... */ }
float calculate_average() { /* ... */ }
```

### Why int main()?

```c
int main()  // Defined by C standard
{
    return 0;  // ✓ Success (0)
               // ✗ Error (non-zero)
}
```

**Return to Operating System:**
- `0` = Successful execution
- Non-zero = Error occurred

---

## <a name="compilation-process"></a>Chapter 8: Compilation Process

### Compilation Workflow

```
HelloPES.c
    ↓
[Preprocessor: gcc -E]
    ↓
HelloPES.i (Preprocessed Code)
    ↓
[Compiler: gcc -S]
    ↓
HelloPES.s (Assembly Code)
    ↓
[Assembler: gcc -c]
    ↓
HelloPES.o (Object Code)
    ↓
[Linker: gcc]
    ↓
a.exe (Executable)
    ↓
[Loader & Execution]
    ↓
Output on Console
```

### Step 1: Preprocessing

```bash
gcc -E HelloPES.c > HelloPES.i
```

**Tasks:**
- Include header files
- Expand macros
- Remove comments

**Original Code:**
```c
#include <stdio.h>
#define PI 3.14

int main() {
    printf("PI = %.2f", PI);
    return 0;
}
```

**After Preprocessing:**
```c
// ... entire contents of stdio.h ...

int main() {
    printf("PI = %.2f", 3.14);  // Macro expanded
    return 0;
}
```

### Step 2: Compilation

```bash
gcc -S HelloPES.c
```

**Compilation Phases:**

```
Lexical Analysis
    ↓ (Tokenization)
Syntax Analysis
    ↓ (Check grammar)
Semantic Analysis
    ↓ (Check meaning)
Intermediate Code Generation
    ↓
Code Optimization
    ↓
Code Generation (Assembly)
```

**Output: HelloPES.s (Assembly Code)**
```asm
.globl main
main:
    pushq   %rbp
    movq    %rsp, %rbp
    leaq    .LC0(%rip), %rdi
    call    printf
    movl    $0, %eax
    popq    %rbp
    retq
```

### Step 3: Assembly

```bash
gcc -c HelloPES.c
```

**Output: HelloPES.o (Object Code - Binary)**

### Step 4: Linking

```bash
gcc HelloPES.o -o HelloPES.exe
```

**Tasks:**
- Combine multiple object files
- Link with libraries
- Resolve external references
- Create executable

### Step 5: Execution

```bash
./HelloPES.exe
```

**What Happens:**
- Loader transfers program to RAM
- Execution begins at main()
- Output displayed

### Complete Compilation Example

```bash
# Source code
echo '#include <stdio.h>
int main() {
    int year = 2026;
    printf("HelloPES: %d\n", year);
    return 0;
}' > HelloPES.c

# Step 1: Preprocess
gcc -E HelloPES.c > HelloPES.i

# Step 2: Compile
gcc -S HelloPES.c

# Step 3: Assemble
gcc -c HelloPES.c

# Step 4: Link
gcc HelloPES.o -o HelloPES.exe

# Step 5: Execute
./HelloPES.exe
```

**Output:**
```
HelloPES: 2026
```

**Or in one step:**
```bash
gcc HelloPES.c -o HelloPES.exe && ./HelloPES.exe
```

### C Compiler Standards

#### C89/C90
```bash
gcc -std=c89 program.c
```

#### C99
```bash
gcc -std=c99 program.c
```

#### C11
```bash
gcc -std=c11 program.c
```

**Check Compiler Standard:**

```c
#include <stdio.h>

int main() {
    printf("C standard: %ld\n", __STDC_VERSION__);
    return 0;
}
```

**Possible Outputs:**
```
C89: Macro not defined
C99: C standard: 199901
C11: C standard: 201112
```

---

## <a name="errors-warnings"></a>Chapter 9: Error Types & Warnings

### Error Classification

```
Programming Errors
    ├── Compile Time Errors (CTE)
    ├── Link Time Errors (LTE)
    ├── Runtime Errors (RTE)
    ├── Logical Errors
    └── Warnings
```

### 1. Compile Time Errors (CTE)

Errors detected by compiler due to syntax violations.

**Characteristics:**
- ✗ Program doesn't compile
- ✗ `.o` file not generated
- Easy to locate (line numbers shown)

**Example: Missing Semicolon**

```c
#include <stdio.h>

int main() {
    printf("hello friends")  // ✗ Missing semicolon
    return 0;
}
```

**Error:**
```
error: expected ';' before 'return'
```

**Example: Missing String Terminator**

```c
#include <stdio.h>

int main() {
    printf("hello friends);  // ✗ Missing closing "
    return 0;
}
```

**Error:**
```
error: missing terminating " character
```

**Example: Missing Parenthesis**

```c
#include <stdio.h>

int main() {
    printf("hello friends";  // ✗ Missing )
    return 0;
}
```

**Error:**
```
error: expected ')' before ';'
```

### 2. Link Time Errors (LTE)

Errors during linking when connecting object files.

**Characteristics:**
- ✓ Program compiles
- ✗ `.exe` not generated
- Cause: Mismatch between function call and definition

**Example: Function Name Mismatch**

```c
#include <stdio.h>

int main() {
    Printf("hello");  // ✗ Printf (capital P)
    printf("world");  // printf (lowercase p)
    return 0;
}
```

**Error:**
```
undefined reference to `Printf'
```

**Example: Missing Function Definition**

```c
#include <stdio.h>

void add(int a, int b);  // Declaration

int main() {
    add(5, 3);
    return 0;
}
// ✗ No definition provided
```

**Error:**
```
undefined reference to `add'
```

### 3. Runtime Errors (RTE)

Errors during program execution.

**Characteristics:**
- ✓ Compiles and links successfully
- ✗ Program terminates abnormally
- Cause: Illegal operations

**Example: Division by Zero**

```c
#include <stdio.h>

int main() {
    int a = 10, b = 0;
    int c = a / b;      // ✗ Division by zero
    printf("%d", c);
    return 0;
}
```

**Error:**
```
Floating point exception (core dumped)
```

**Example: Array Out of Bounds**

```c
#include <stdio.h>

int main() {
    int arr[3] = {1, 2, 3};
    printf("%d", arr[5]);  // ✗ Accessing outside bounds
    return 0;
}
```

**Error:**
```
Segmentation fault (core dumped)
```

**Example: Null Pointer Dereference**

```c
#include <stdio.h>

int main() {
    int *ptr = NULL;
    printf("%d", *ptr);  // ✗ Dereference NULL
    return 0;
}
```

**Error:**
```
Segmentation fault (core dumped)
```

### 4. Logical Errors

Program runs but produces wrong output.

**Characteristics:**
- ✓ Compiles, links, executes
- ✗ Output incorrect
- Program doesn't crash
- Hardest to find

**Example: Wrong Formula**

```c
#include <stdio.h>

int main() {
    int length = 5, width = 10;
    int area = length + width;  // ✗ Should be *
    printf("Area: %d\n", area);
    return 0;
}
```

**Output:**
```
Area: 15  // ✗ Wrong! Expected 50
```

### 5. Warnings

Non-fatal messages indicating potential issues.

**Characteristics:**
- Program compiles and runs
- Indicates possible issues
- Should be fixed

**Example: Uninitialized Variable**

```c
#include <stdio.h>

int main() {
    int a;  // ✗ Not initialized
    printf("%d", a);
    return 0;
}
```

**Warning:**
```
warning: 'a' is used uninitialized
```

**Example: Unused Variable**

```c
#include <stdio.h>

int main() {
    int unused = 10;  // ✗ Never used
    printf("Hello\n");
    return 0;
}
```

**Warning:**
```
warning: unused variable 'unused'
```

### Viewing Warnings

```bash
# Show all warnings
gcc -Wall program.c

# Show extra warnings
gcc -Wextra program.c

# Both
gcc -Wall -Wextra program.c

# Treat as errors
gcc -Werror program.c
```

---

## <a name="printf"></a>Chapter 10: Formatted Output - printf()

### Introduction

**Syntax:**
```c
int printf(const char *format, arg1, arg2, ...);
```

**Returns:** Number of characters printed

**Purpose:** Send formatted output to screen

### Format String

```
%[flags][field_width][.precision]conversion_character
```

### Conversion Specifiers

| Specifier | Meaning | Example |
|-----------|---------|---------|
| `%d` | Integer | `printf("%d", 42);` → `42` |
| `%f` | Float | `printf("%f", 3.14);` → `3.140000` |
| `%c` | Character | `printf("%c", 'A');` → `A` |
| `%s` | String | `printf("%s", "Hi");` → `Hi` |
| `%x` | Hex (lower) | `printf("%x", 255);` → `ff` |
| `%X` | Hex (upper) | `printf("%X", 255);` → `FF` |
| `%o` | Octal | `printf("%o", 8);` → `10` |
| `%p` | Pointer | `printf("%p", &x);` → `0x7fff...` |
| `%%` | Percent | `printf("%%");` → `%` |

### Field Width

Minimum width for output.

```c
printf("|%5d|\n", 12);       // |   12|
printf("|%5d|\n", 123);      // |  123|
printf("|%5d|\n", 12345);    // |12345|
printf("|%5d|\n", 123456);   // |123456|
```

### Left Alignment

```c
printf("|%-5d|\n", 12);      // |12   |
printf("|%-5d|\n", 123);     // |123  |
```

### Flags

| Flag | Meaning | Example |
|------|---------|---------|
| `-` | Left align | `%-5d` |
| `+` | Force sign | `%+d` → `+42` |
| ` ` | Space | `% d` → ` 42` |
| `0` | Zero pad | `%05d` → `00042` |
| `#` | Alternate | `%#x` → `0x2a` |

**Examples:**

```c
printf("%+d\n", 10);        // +10
printf("%+d\n", -10);       // -10
printf("%05d\n", 42);       // 00042
printf("% d\n", 10);        //  10
printf("%#x\n", 26);        // 0x1a
```

### Precision

Decimal places for floats, max chars for strings.

```c
printf("%.2f\n", 3.14159);      // 3.14
printf("%.4f\n", 3.14159);      // 3.1416
printf("%.3s\n", "Computer");   // Com
printf("%.5d\n", 12);           // 00012
```

### Width + Precision

```c
printf("|%8.2f|\n", 12.3456);    // |   12.35|
printf("|%10s|\n", "CSE");       // |       CSE|
printf("|%-10s|\n", "CSE");      // |CSE       |
```

### Complete printf() Example

```c
#include <stdio.h>

int main() {
    printf("===== printf() Examples =====\n\n");
    
    // Integers
    printf("Decimal: %d\n", 42);
    printf("Hex: %x\n", 255);
    printf("Octal: %o\n", 8);
    
    // Floating Point
    printf("Float: %.2f\n", 3.14159);
    printf("Scientific: %e\n", 1234.5);
    
    // Strings & Characters
    printf("String: %s\n", "Hello");
    printf("Char: %c\n", 'A');
    
    // Formatting
    printf("|%10s|\n", "Right");
    printf("|%-10s|\n", "Left");
    printf("|%05d|\n", 42);
    printf("|%+d|\n", 42);
    
    // Return Value
    int chars = printf("Test\n");
    printf("Characters printed: %d\n", chars);
    
    return 0;
}
```

**Output:**
```
===== printf() Examples =====

Decimal: 42
Hex: ff
Octal: 10
Float: 3.14
Scientific: 1.234500e+03
String: Hello
Char: A
|     Right|
|Left      |
|00042|
|+42|
Characters printed: 5
```

---

## <a name="scanf"></a>Chapter 11: Formatted Input - scanf()

### Introduction

**Syntax:**
```c
int scanf(const char *format, arg1, arg2, ...);
```

**Returns:**
- Positive: Number of values successfully read
- 0: No value stored
- Negative: EOF reached

### Format String

```
%[assignment_suppression][field_width][modifier]conversion_char
```

### Conversion Characters

| Character | Meaning |
|-----------|---------|
| `d` | Decimal integer |
| `f` | Float |
| `c` | Character |
| `s` | String |
| `x` | Hexadecimal |

### Field Width

Maximum characters to read.

```c
int input;
scanf("%2d", &input);  // Read max 2 digits
```

### Length Modifiers

```c
short a;
int b;
long c;

scanf("%hd", &a);  // short
scanf("%d", &b);   // int
scanf("%ld", &c);  // long
```

### Assignment Suppression

Read but don't store using `*`.

```c
int a, c;
scanf("%d %*d %d", &a, &c);

// Input: 100 200 300
// Result: a=100, c=300 (200 skipped)
```

### Basic Input Example

```c
#include <stdio.h>

int main() {
    int age;
    float salary;
    char grade;
    
    printf("Enter age: ");
    scanf("%d", &age);
    
    printf("Enter salary: ");
    scanf("%f", &salary);
    
    printf("Enter grade: ");
    scanf("%c", &grade);
    
    printf("\nAge: %d\n", age);
    printf("Salary: %.2f\n", salary);
    printf("Grade: %c\n", grade);
    
    return 0;
}
```

**Input:**
```
25
50000.50
A
```

**Output:**
```
Age: 25
Salary: 50000.50
Grade: A
```

### String Functions: sprintf() and sscanf()

#### sprintf() - Format to String

```c
#include <stdio.h>

int main() {
    char buffer[100];
    int age = 25;
    
    sprintf(buffer, "Age is %d years", age);
    printf("%s\n", buffer);
    
    return 0;
}
```

**Output:**
```
Age is 25 years
```

#### sscanf() - Parse String

```c
#include <stdio.h>

int main() {
    char str[] = "ID=101 Name=Computer Marks=95.75";
    
    int id;
    char name[20];
    float marks;
    
    sscanf(str, "ID=%d Name=%s Marks=%f", &id, name, &marks);
    
    printf("ID: %d\n", id);
    printf("Name: %s\n", name);
    printf("Marks: %.2f\n", marks);
    
    return 0;
}
```

**Output:**
```
ID: 101
Name: Computer
Marks: 95.75
```

---

## <a name="unformatted-io"></a>Chapter 12: Unformatted I/O Functions

### Character Functions

#### putchar()

Output single character.

```c
#include <stdio.h>

int main() {
    putchar('H');
    putchar('i');
    putchar('\n');
    return 0;
}
```

**Output:**
```
Hi
```

#### getchar()

Input single character.

```c
#include <stdio.h>

int main() {
    char ch;
    printf("Enter character: ");
    ch = getchar();
    printf("You entered: ");
    putchar(ch);
    return 0;
}
```

### String Functions

#### puts()

Output string (adds newline).

```c
#include <stdio.h>

int main() {
    puts("Hello World");
    puts("Welcome");
    return 0;
}
```

**Output:**
```
Hello World
Welcome
```

#### fgets() (Safe Alternative to gets())

```c
#include <stdio.h>

int main() {
    char name[50];
    
    printf("Enter name: ");
    fgets(name, sizeof(name), stdin);
    
    printf("Name: %s", name);
    return 0;
}
```

---

## <a name="features"></a>Chapter 13: Features & Applications of C

### Key Features

#### 1. Simple and Efficient
```c
// Simple syntax
int sum = a + b;
printf("%d", sum);
```

#### 2. Portability
```c
// Same code runs everywhere
```

#### 3. Fast Execution
```c
// Compiled language
// Direct hardware access
```

#### 4. Extensibility
```c
// Easy to add features
```

#### 5. Rich Libraries
```c
#include <stdio.h>
#include <math.h>
#include <string.h>
```

#### 6. Dynamic Memory Allocation
```c
#include <stdlib.h>

int *arr = (int *)malloc(10 * sizeof(int));
free(arr);
```

#### 7. Pointers
```c
int a = 10;
int *ptr = &a;
printf("%d", *ptr);  // Dereference
```

#### 8. Recursion
```c
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
```

### Applications

- **Operating Systems:** Unix, Linux, Windows
- **Embedded Systems:** IoT, Microcontrollers
- **Databases:** MySQL, PostgreSQL
- **Compilers:** GCC, Clang
- **Game Development:** Graphics engines
- **AI & Machine Learning:** Performance optimization

---

## <a name="examples"></a>Chapter 14: Complete Working Examples

### Example 1: Basic Variables and Output

```c
#include <stdio.h>

int main() {
    int age = 25;
    float height = 5.9;
    char grade = 'A';
    
    printf("Age: %d years\n", age);
    printf("Height: %.1f feet\n", height);
    printf("Grade: %c\n", grade);
    
    return 0;
}
```

**Output:**
```
Age: 25 years
Height: 5.9 feet
Grade: A
```

### Example 2: Data Type Sizes

```c
#include <stdio.h>

int main() {
    printf("Data Type Sizes:\n");
    printf("int: %zu bytes\n", sizeof(int));
    printf("float: %zu bytes\n", sizeof(float));
    printf("double: %zu bytes\n", sizeof(double));
    printf("char: %zu bytes\n", sizeof(char));
    printf("short: %zu bytes\n", sizeof(short));
    printf("long: %zu bytes\n", sizeof(long));
    
    return 0;
}
```

### Example 3: Type Qualifiers

```c
#include <stdio.h>

int main() {
    // Const - cannot modify
    const int MAX = 100;
    printf("Maximum: %d\n", MAX);
    
    // Static - preserves value
    static int counter = 0;
    counter++;
    printf("Counter: %d\n", counter);
    
    return 0;
}
```

### Example 4: Input and Output

```c
#include <stdio.h>

int main() {
    int num1, num2, sum;
    
    printf("Enter first number: ");
    scanf("%d", &num1);
    
    printf("Enter second number: ");
    scanf("%d", &num2);
    
    sum = num1 + num2;
    printf("Sum: %d\n", sum);
    
    return 0;
}
```

### Example 5: Formatted Input/Output

```c
#include <stdio.h>

int main() {
    int id;
    char name[50];
    float gpa;
    
    printf("Enter Student ID: ");
    scanf("%d", &id);
    
    printf("Enter Name: ");
    scanf("%s", name);
    
    printf("Enter GPA: ");
    scanf("%f", &gpa);
    
    printf("\n===== Student Details =====\n");
    printf("ID: %d\n", id);
    printf("Name: %s\n", name);
    printf("GPA: %.2f\n", gpa);
    
    return 0;
}
```

### Example 6: String Processing with sscanf

```c
#include <stdio.h>

int main() {
    char data[] = "ID=1001 Name=John Salary=50000.50";
    
    int id;
    char name[50];
    float salary;
    
    sscanf(data, "ID=%d Name=%s Salary=%f", &id, name, &salary);
    
    printf("Employee ID: %d\n", id);
    printf("Name: %s\n", name);
    printf("Salary: $%.2f\n", salary);
    
    return 0;
}
```

**Output:**
```
Employee ID: 1001
Name: John
Salary: $50000.50
```

### Example 7: Number Systems

```c
#include <stdio.h>

int main() {
    int num = 42;
    
    printf("Decimal: %d\n", num);
    printf("Hexadecimal: %x\n", num);
    printf("Octal: %o\n", num);
    
    return 0;
}
```

**Output:**
```
Decimal: 42
Hexadecimal: 2a
Octal: 52
```

### Example 8: Printf Formatting

```c
#include <stdio.h>

int main() {
    printf("===== Printf Formatting =====\n\n");
    
    // Field width
    printf("Width: |%10s|\n", "Hello");
    
    // Left align
    printf("Left: |%-10s|\n", "World");
    
    // Zero padding
    printf("Padding: %05d\n", 42);
    
    // Precision
    printf("Decimal: %.2f\n", 3.14159);
    
    // Force sign
    printf("Sign: %+d\n", 42);
    
    return 0;
}
```

---

## Quick Reference Guide

### Variable Declaration
```c
int age;
float salary;
char grade;
double precise;
```

### Data Types and Sizes
```c
char        1 byte     -128 to 127
short       2 bytes    -32,768 to 32,767
int         4 bytes    -2,147,483,648 to 2,147,483,647
long        8 bytes    Very large range
float       4 bytes    ~6-7 decimal digits
double      8 bytes    ~15-17 decimal digits
```

### Common printf Specifiers
```c
%d          Integer
%f          Float (6 decimal places)
%.2f        Float with 2 decimal places
%c          Character
%s          String
%x          Hexadecimal
%p          Pointer address
```

### Escape Sequences
```c
\n          Newline
\t          Tab
\r          Carriage return
\"          Double quote
\'          Single quote
\\          Backslash
```

### Compilation Commands
```bash
gcc program.c                           // Compile and link
gcc program.c -o program.exe            // With custom name
gcc -Wall program.c                     // Show warnings
gcc -std=c99 program.c                  // Use C99 standard
gcc -E program.c > program.i            // Preprocess only
gcc -S program.c                        // Generate assembly
gcc -c program.c                        // Generate object file
```

---

## Summary

### Key Concepts Covered

1. **Tokens & Identifiers** - Basic building blocks
2. **Keywords** - 32 reserved words
3. **Variables** - Named storage with 6 characteristics
4. **Data Types** - int, float, double, char, void
5. **Type Qualifiers** - const, volatile, static, register
6. **Program Structure** - Organized sections
7. **Compilation** - 5-step process
8. **Errors** - CTE, LTE, RTE, Logical, Warnings
9. **I/O Functions** - printf, scanf, puts, gets, sprintf, sscanf
10. **Features** - Portability, speed, extensibility

### Best Practices

- Always initialize variables before use
- Use meaningful variable names
- Check scanf() return value
- Use const for constants
- Enable compiler warnings (`-Wall`)
- Use C standard (preferably C99 or C11)
- Write modular code with functions
- Add comments and documentation
- Test edge cases
- Handle errors gracefully

---

**End of C Programming Complete Guide v1.0**

**Author:** Prof. Sonali Kalekar  
**Compiled by:** Pragun-07  
**Last Updated:** June 2026

---
