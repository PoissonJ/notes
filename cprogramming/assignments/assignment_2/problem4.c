#include <stdio.h>
#include <stdlib.h>

int euclidean(int m, int n) {
    if (n == 0) {return m;}
    return euclidean(n, m % n);
}

int main() {
    int a, b, answer;
    scanf("%d", &a);
    scanf("%d", &b);
    answer = euclidean(a, b);
    printf("%d\n", answer);
    return 0;
}
