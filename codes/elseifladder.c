//else - if ladder
//marks classification
#include <stdio.h>
int main()
{
    int n = 75;

    if (n >= 50)
        printf("Pass");
    else if (n >= 75)
        printf("Distinction");
    else
        printf("Fail");

    return 0;
}
//though n>=75, elseif block is never executed
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

//---------------------------------------------
//largest of 3 numbers 
#include <stdio.h>
int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    if (a >= b && a >= c)
        printf("A is largest");
    else if (b >= a && b >= c)
        printf("B is largest");
    else
        printf("C is largest");

    return 0;
}
//--------------------------------
//triangle type
// Triangle rule:
//Sum of any two sides must be greater than the third side.
#include <stdio.h>

int main()
{
    int a, b, c;

    printf("Enter three sides: ");
    scanf("%d %d %d", &a, &b, &c);

    // Check triangle validity
    if (a + b <= c || b + c <= a || a + c <= b)
        printf("Not a triangle");

    // All sides equal
    else if (a == b && b == c)
        printf("Equilateral triangle");

    // Any two sides equal
    else if (a == b || b == c || a == c)
        printf("Isosceles triangle");

    // All sides different
    else
        printf("Scalene triangle");

    return 0;
}

//------------------------------
//bitwise check
#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);

    if (n & 1)//if last bit of n =1 odd number, else even
        printf("Odd");
    else if (!(n & 1))
        printf("Even");
    else
        printf("Impossible");

    return 0;
}
//-----------------------------------------------------
//program to check whether a given number is a Power of 2 using bitwise.
#include <stdio.h>

int main()
{
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n <= 0)
        printf("Invalid");
    else if ((n & (n - 1)) == 0)//returns 0 if number is power of 2
        printf("Power of 2");
    else
        printf("Not power of 2");

    return 0;
}
/*A number is a power of 2 if it has only one bit set in binary.
eg: 8  = 1000
	7  = 0111
-------------
		1000
	-   0111
		-----
		0000
*/
//--------------------------------------
//reverse a 3 digit number using else if ladder
#include <stdio.h>

int main()
{
    int n, reverse;

    printf("Enter a 3-digit number: ");
    scanf("%d", &n);

    if (n < 100 || n > 999)
        printf("Invalid input");

    else if (n >= 100 && n <= 999)
    {
        int hundreds = n / 100;
        int tens = (n / 10) % 10;
        int units = n % 10;

        reverse = units * 100 + tens * 10 + hundreds;

        printf("Reversed number = %d", reverse);
    }

    else
        printf("Error");

    return 0;
}
