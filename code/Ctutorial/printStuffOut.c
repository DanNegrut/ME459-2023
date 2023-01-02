#include<stdio.h>

int main() {
    int d;
    char c;
    short s;
    int* p;
    int arr[2];
    printf(" %p\n %p\n %p\n %p\n %p\n", &d, &c, &s, &p, arr);
    return 0;
}
