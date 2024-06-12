#include <stdio.h>

int fls(unsigned int x)
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

int main()
{
    for (int number = 1; number <= 20; number++) {
        printf("number : %d\n", number);
        printf("%d\n", fls(number));
        printf("%d\n", fls_branchless(number));
    }
    
    return 0;
}