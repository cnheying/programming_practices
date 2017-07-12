#include <cstdlib>
#include <cstdio>
#include<climits>
#include<cinttypes>
int reverse(int x) {
	bool isNeg = false;
	if (x<0) {
		isNeg = true;
		x = -x;
	}
	int64_t inv_x = 0;
	do {
		inv_x *= 10; 
			inv_x += x % 10;
	} while (x /= 10);
	if (inv_x>INT_MAX || inv_x<INT_MIN) {
		return 0;
	}
	if (isNeg) {
		inv_x = -inv_x;
	}
	return inv_x;
}

#include<cassert>
int main(char* argv, int argc) {
	assert(reverse(0) == 0);
	assert(reverse(-1) == -1);
	assert(reverse(123) == 321);
	assert(reverse(1000000009) == 0);
	printf("ok No 7\r\n");
	return EXIT_SUCCESS;
}