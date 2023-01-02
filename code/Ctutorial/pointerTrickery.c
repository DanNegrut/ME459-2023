#include "stdlib.h"
#include "stdio.h"

void update_array(float* a, float* b, unsigned int len) {
    for (unsigned int i = 0; i < len; i++)
        a[i] = b[i] + 8.0f;
}

int main() {
    float a[7] = { 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f };
    unsigned int length = 7;
    unsigned int offset = 2;

    printf("Content of array a beffore update:\n");
    for (unsigned int i = 0; i < length; i++)
        printf("a[%d]=%f\n", i, a[i]);

    update_array(a + offset, a, length - offset);

    printf("Content of array a after update:\n");
    for (unsigned int i = 0; i < length; i++)
        printf("a[%d]=%f\n", i, a[i]);

    return 0;
}
