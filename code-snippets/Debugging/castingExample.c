#include <stdio.h>

int main() {
    int a[2] = { 42, 54 };
    char* c = ((char*)&a[0]) + 10;
    *c = 'w';
    printf("First entry:%d\n", a[0]);
    printf("Second entry:%d\n", a[1]);
    return 0;
}