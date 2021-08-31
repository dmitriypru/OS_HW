#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    printf("INT MAX\n\nVALUE: %d\nSIZE: %lu\n\n\nFLOAT MAX\n\nnVALUE: %f\nSIZE: %lu\n\n\nDOUBLE MAX\n\nVALUE: %lf\nSIZE: %lu", INT_MAX, sizeof(INT_MAX), FLT_MAX, sizeof(FLT_MAX), DBL_MAX, sizeof(DBL_MAX));
    return 0;
}