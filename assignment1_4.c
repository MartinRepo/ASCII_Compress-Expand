#include <stdio.h>

int main() {
    int a, b, n;
    scanf("%d%d%d", &a, &b, &n);

    // compute integer part and remainder.
    int remainder = a % b;
    int decimalPart[n + 1];
    int i;
    for (i = 0; i < n + 1 && remainder != 0; i++) {
        remainder *= 10;
        decimalPart[i] = remainder / b;
        remainder = remainder % b;
    }
    decimalPart[i] = 0;

    //output the n-th character
    if (i <= n) {
        printf("0\n");
    } else {
        printf("%d\n", decimalPart[n-1]);
    }

    return 0;
}
