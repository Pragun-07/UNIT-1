
//---------if - else --------------------------------
// Check if number is exactly a 3-digit palindrome (no loop)
/*#include <stdio.h>

int main()
{
    int n;
    printf("Enter 3-digit number: ");
    scanf("%d", &n);

    if (n/100 == n%10)
	// division extracts the first digit and % extracts lastdigit
        printf("Palindrome");
    else
        printf("Not Palindrome");

    return 0;
}*/
//--------------------------------------------------------------
// Check if character is consonent 
/*#include <stdio.h>
int main()
{
    char ch;
    printf("Enter character: ");
    scanf(" %c", &ch);

    if (((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) &&
        !(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||
          ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'))
        printf("Consonant");
    else
        printf("Not a consonant");

    return 0;
}*/
//-----------------------------------------------------------
//Check if a 3-digit number's middle digit is largest
/*#include <stdio.h>
int main()
{
    int n;
    printf("Enter 3-digit number: ");
    scanf("%d", &n);

    if ((n/10)%10 > n/100 && (n/10)%10 > n%10)
        printf("Middle digit is largest");
    else
        printf("Condition not satisfied");

    return 0;
}*/
//hint - middle digit > first digit
//AND
//middle digit > last digit

//eg 572
//572/100 = 5.72 = 5 (extracting the 1st digit of the number)
//572%10 = 2 (extracting the last digit of the number)
//(572/10) % 10 (extracting the middle digit of the number)
//57.2 = 57%10 = 7
//---------------------------------------------
// check if product of 3 digit number is odd
/*#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);

    if ((n/100 * (n/10)%10 * n%10) % 2 != 0)
        printf("Product of digits is odd");
    else
        printf("Product is even");

    return 0;
}*/
//------------------------------------------
//Check if number is between 100–999 but digits are not same
/*#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);

    if (n>=100 && n<=999 &&
        !(n/100==(n/10)%10 && (n/10)%10==n%10))
        printf("3-digit and digits not all same");
    else
        printf("Condition not satisfied");

    return 0;
}*/
//----------------------------------------------------------
// check if a number is an armstrong number
//eg : 153 -> 1^3 + 5^3 + 3^3 =153
/*#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);

    if ((n/100)*(n/100)*(n/100) +
        ((n/10)%10)*((n/10)%10)*((n/10)%10) +
        (n%10)*(n%10)*(n%10) == n)
        printf("Armstrong number");
    else
        printf("Not Armstrong");

    return 0;
}*/
