#include <stdio.h>

int i_sqrt(int x)
{
    int d = 1UL << ((31 - __builtin_clz(x)) & ~1UL);

    printf("x : %d\n", x);
    printf("__builtin_clz(x) : %d\n", __builtin_clz(x));
    
    printf("d : %d\n", d);

    return 0;
}

int main() {
    for (int number = 0; number <= 20; number++) {
        i_sqrt(number);
        printf("\n");
    }
    
    return 0;
}