#include <stdio.h>

// Calculates the greatest common divisor
int gcd(int n1, int n2) {

    if (n2== 0) {
        return n1;
    } else {
        return gcd(n2, n1%n2);
    }
}
// Calculates the least common multiple
int lcm(int n1, int n2) {
    return n1*n2/gcd(n1, n2);
    }

int main() {
    int n1, n2;
    printf("Enter first integer n1: ");
    scanf("%d", &n1);
    printf("Enter second integer n2: ");
    scanf("%d", &n2);
    printf("The greatest common divisor of n1 and n2 is %d\n", gcd(n1, n2));
    printf("The least common multiple of n1 and n2 is %d\n", lcm(n1, n2));
    return 0;
}
