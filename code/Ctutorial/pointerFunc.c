#include <stdio.h>

int someFunc(float a, float b) {
    if (a < b)
        return 1;
    else
        return 0;
}

int main(int argc, char **argv) {
    int(*compare)(float, float);
    compare = someFunc;
    printf("Address of function is: %p\n", (void*)compare);
    printf("Comparing two vals: 5 is less then 6: %d\n", compare(5.f, 6.f));
    return 0;
}