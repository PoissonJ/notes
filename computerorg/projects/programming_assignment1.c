#include <stdlib.h>
#include <stdio.h>

int num, reverse = 0, temp;

int main() {

    printf("Programming assignment 1 for CDA3101\n");
    printf("This palindrome checker only deals with postive integer number.\n");
    printf("Enter a number to check if it is a palindrome or not.\n");
    scanf("%d", &num);

    temp = num;

    while( temp != 0) {
        reverse = reverse* 10;
        reverse = reverse + temp % 10;
        temp = temp / 10;
    }

    if (num == reverse) {
        printf("%d is a palindrome number.\n", num);
    }
    else {
        printf("%d is not a palindrome number.\n", num);
    }

    return 0;
}
