#include <stdio.h>

int main(int argc, char *argv[]) {

    int i = 3;
    float f = i;

    printf("%d %f\n", i, f);

    f = (float)i;
    printf("%d %f\n", i, f);

    if (i == f) {
        printf("i == f\n");
    } else {
        printf("i != f\n");
    }

    return 0;

}
