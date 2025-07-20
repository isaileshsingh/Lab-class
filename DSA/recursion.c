#include <stdio.h>
#include <string.h>

// factorial: calculates n! recursively
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// sumOfDigits: returns the sum of all digits in a number
int sumOfDigits(int n) {
    if (n == 0) return 0;
    return (n % 10) + sumOfDigits(n / 10);
}

// fibonacci: returns the nth number in the Fibonacci sequence
int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// isPalindrome: checks if a string is a palindrome
int isPalindrome(char str[], int start, int end) {
    if (start >= end) return 1;
    if (str[start] != str[end]) return 0;
    return isPalindrome(str, start + 1, end - 1);
}

// towerOfHanoi: prints steps to solve Tower of Hanoi problem
void towerOfHanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    towerOfHanoi(n - 1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    towerOfHanoi(n - 1, aux, to, from);
}

// sumOddDigits: returns the sum of only the odd digits in a number
int sumOddDigits(int n) {
    if (n == 0) return 0;
    int digit = n % 10;
    if (digit % 2 != 0) return digit + sumOddDigits(n / 10);
    return sumOddDigits(n / 10);
}

int main() {
    int choice, n, result;
    char str[100];

    printf("1. Factorial\n");
    printf("2. Sum of Digits\n");
    printf("3. Fibonacci (nth number)\n");
    printf("4. Check Palindrome (String)\n");
    printf("5. Tower of Hanoi\n");
    printf("6. Sum of Odd Digits\n");
    printf("Enter your choice (1-6): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Factorial: Multiplies the number with all positive integers below it.\n");
            printf("Enter a number: ");
            scanf("%d", &n);
            result = factorial(n);
            printf("Factorial of %d = %d\n", n, result);
            break;
        case 2:
            printf("Sum of Digits: Adds each digit in the number recursively.\n");
            printf("Enter a number: ");
            scanf("%d", &n);
            result = sumOfDigits(n);
            printf("Sum of digits = %d\n", result);
            break;
        case 3:
            printf("Fibonacci: Returns nth number where each term is sum of previous two.\n");
            printf("Enter n: ");
            scanf("%d", &n);
            result = fibonacci(n);
            printf("Fibonacci number at position %d = %d\n", n, result);
            break;
        case 4:
            printf("Palindrome: Checks if a string reads the same forward and backward.\n");
            printf("Enter a string: ");
            scanf("%s", str);
            if (isPalindrome(str, 0, strlen(str) - 1))
                printf("Palindrome\n");
            else
                printf("Not a palindrome\n");
            break;
        case 5:
            printf("Tower of Hanoi: Moves disks between rods using recursion.\n");
            printf("Enter number of disks: ");
            scanf("%d", &n);
            towerOfHanoi(n, 'A', 'C', 'B');
            break;
        case 6:
            printf("Sum of Odd Digits: Adds only odd digits in the number.\n");
            printf("Enter a number: ");
            scanf("%d", &n);
            result = sumOddDigits(n);
            printf("Sum of odd digits = %d\n", result);
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}
