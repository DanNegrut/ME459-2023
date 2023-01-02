#include <stdio.h>

int main() {
    float fVal = 16777215.f;
    int iVal = 16777215;
    int res = iVal - fVal;
    printf("First diff: %d\n", res);

    fVal = 16777216.f;
    iVal = 16777216;
    res = iVal - fVal;
    printf("Second diff: %d\n", res);

    fVal = 16777217.f;  // 
    iVal = 16777217;         //
    res = iVal - (int)fVal;       //
    printf("Third diff: %d\n", res);

    fVal = 16777218.f;
    iVal = 16777218;
    res = iVal - fVal;
    printf("Fourth diff: %d\n", res);

    fVal = (int) 16777219.f;
    iVal = 16777219;
    res = iVal - fVal;
    printf("Fifth diff: %d\n", res);

    fVal = 167772190.f;
    iVal = 167772190;
    res = iVal - (int)fVal;
    printf("Sixth diff: %d\n", res);

    fVal = 1677721900.f;
    iVal = 1677721900;
    res = iVal - (int)fVal;
    printf("Last diff: %d\n", res);

    return 0;
}
