#include <stdio.h>

int fls_branchless(unsigned int x)
{
	int r = 32;
    int shift;

	if (!x)
		return 0;
    shift = ((x & 0xffff0000u) == 0) << 4; /* 16 */
    x <<= shift;
    r -= shift;

    shift = ((x & 0xff000000u) == 0) << 3; /* 8 */
    x <<= shift;
    r -= shift;

    shift = ((x & 0xf0000000u) == 0) << 2; /* 4 */
    x <<= shift;
    r -= shift;

    shift = ((x & 0xc0000000u) == 0) << 1; /* 2 */
    x <<= shift;
    r -= shift;

    shift = ((x & 0x80000000u) == 0); /* 1 */
    x <<= shift;
    r -= shift;
	
	return r;
}

int i_sqrt(int x)
{
    if (x <= 1) /* Assume x is always positive */
        return x;

    int c = 0;
    for (int d = 1UL << ((fls_branchless(x)) & ~1UL); d; d >>= 2) {
        int y = c + d;
        c >>= 1;
        if (x >= y)
            x -= y, c += d;               
    }
    return c;
}

int main() {
    for (int number = 1; number <= 20; number++) {
        printf("i_sqrt(%d) : %d\n", number, i_sqrt(number));
    }
    
    return 0;
}