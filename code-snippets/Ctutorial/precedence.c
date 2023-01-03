#include<stdio.h>

int main() {
    int i = 4;
    int j = 4;
    int a = i++;
    int b = ++j;

    printf("a is: %d\n", a);
    printf("b is: %d\n", b);

    return 0;
}