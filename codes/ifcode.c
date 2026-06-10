// programs using if 
//program to check if a number is divisible by 3 and 5 not divisble by 15
/*
#include <stdio.h>

int main()
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if ((num % 3 == 0 || num % 5 == 0) && num % 15 != 0)
    {
        printf("Divisible by 3 or 5 but NOT by 15\n");
    }
    else
    {
        printf("Condition not satisfied\n");
    }

    return 0;
}

//--------------------------------------------------
//find the largest of 3 numbers using if statment only
/*#include <stdio.h>

int main()
{
    int a, b, c;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a >= b && a >= c)
        printf("Largest = %d", a);

    if (b > a && b >= c)
        printf("Largest = %d", b);

    if (c > a && c > b)
        printf("Largest = %d", c);

    return 0;
}*/
//----------------------------------------------------------
//check if a character is uppercase, lowercase, digit or special character
/*#include <stdio.h>

int main()
{
    char ch;
    printf("Enter a character: ");
    scanf(" %c", &ch);

    if (ch >= 'A' && ch <= 'Z') //65 && 90
        printf("Uppercase");

    if (ch >= 'a' && ch <= 'z')// 97 &&122
        printf("Lowercase");

    if (ch >= '0' && ch <= '9') //'0' ascii value i.e 48 is stored
        printf("Digit");

    if (!( (ch >= 'A' && ch <= 'Z') || //If NOT (uppercase OR lowercase OR digit)
           (ch >= 'a' && ch <= 'z') || 
           (ch >= '0' && ch <= '9') ))
        printf("Special Character");

    return 0;
}*/
//--------------------------------------------------------------
//salary calculation with bonus rule
/*Rule:
If salary > 50000 → 10% bonus
If salary between 30000–50000 → 7%

Otherwise → 5%*/
/*#include <stdio.h>

int main()
{
    float salary, bonus;

    printf("Enter salary: ");
    scanf("%f", &salary);

    if (salary > 50000)
        bonus = salary * 0.10;

    if (salary <= 50000 && salary >= 30000)
        bonus = salary * 0.07;

    if (salary < 30000)
        bonus = salary * 0.05;

    printf("Bonus = %.2f", bonus);

    return 0;
}*/
//----------------------------------------------
//swap if a number is greater than other
#include <stdio.h>

int main()
{
    int a, b, temp;
    printf("Enter two numbers: a and b ");
    scanf("%d %d", &a, &b);

    if (a > b)
    {
        temp = a;
        a = b;
        b = temp;
    }

    printf("a = %d, b = %d", a, b);

    return 0;
}
