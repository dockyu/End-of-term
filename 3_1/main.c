#include <stdio.h>

int __fls(unsigned int x)
{
	int r = 32;

	if (!x)
		return 0;
	if (!(x & 0xffff0000u)) {
		x <<= 16;
		r -= 16;
	}
	if (!(x & 0xff000000u)) {
		x <<= 8;
		r -= 8;
	}
	if (!(x & 0xf0000000u)) {
		x <<= 4;
		r -= 4;
	}
	if (!(x & 0xc0000000u)) {
		x <<= 2;
		r -= 2;
	}
	if (!(x & 0x80000000u)) {
		x <<= 1;
		r -= 1;
	}
	return r;
}

int i_sqrt(int x)
{
    if (x <= 1) /* Assume x is always positive */
        return x;

    int c = 0;
    for (int d = 1UL << ((__fls(x)) & ~1UL); d; d >>= 2) {
        int y = c + d;
        c >>= 1;
        if (x >= y)
            x -= y, c += d;               
    }
    return c;
}

int main() {
    int number = 10;
    printf("i_sqrt(%d) : %d\n", number, i_sqrt(number));
    return 0;
}