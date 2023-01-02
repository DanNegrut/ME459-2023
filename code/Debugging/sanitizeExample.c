#include <stdio.h>

int sum(int* x, int len) {
    int total = 0;
    for (int i = 0; i < len; i++) {
        total += x[i];
    }
    return total;
}

int main() {
    int x[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int mySum = sum(x, 9);
    printf("sum = %d\n", mySum);
    int b;
    mySum += b;
    printf("Just added b to sum:%d\n", mySum);
    return 0;
}
