#include <stdio.h>

int main() {
    int a[20] = {
   0,  2,    4,   6,    7,   7,    7,    6,  4,    2,};

    for (int i = 0; i < 10; ++i) {
        printf("        ");
        for (int j = 0; j < a[i]; ++j) {
            printf("*");
        }
        printf("\n");
    }
    for (int i = 0; i <10; ++i) {

    }
    return 0;
}
