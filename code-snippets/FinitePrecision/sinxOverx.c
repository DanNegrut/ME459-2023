#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[]) {
    int size_d = 11;
    float x = 1.0f;

    // in infinite precision, you wouldn't see a zero "diff" value...
    for (int i = 0; i < size_d; ++i) {
        float ratio = sinf(x) / x;
        printf("x: %e; ratio: %.10e; diff: %e\n", x, ratio, 1.0f - ratio);
        x *= 0.1f;
    }

    return 0;
}
