#include <stdio.h>

int i_sqrt(int x)
{
    if (x <= 1) /* Assume x is always positive */
        return x;

    int c = 0;
    for (int d = 1UL << ((31 - __builtin_clz(x)) & ~1UL); d; d >>= 2) {
        int y = c + d;
        c >>= 1;
        if (x >= y)
            x -= y, c += d;               
    }
    return c;
}

int main() {
    int number = 16;
    printf("i_sqrt(%d) : %d\n", number, i_sqrt(number));
    return 0;
}