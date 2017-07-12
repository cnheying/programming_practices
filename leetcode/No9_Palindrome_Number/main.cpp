bool isPalindrome(int x) {
	if (x<0)
	{
		return false;
	}
	int ix = 0;
	int x0 = x;
	do {
		ix *= 10;
		ix += x % 10;
		x /= 10;
	} while (x > 0);
	return x0 == ix;
}


#include <cstdio>
#include <cstdlib>
#include<cassert>
int main(char* argv, int argc) {
	assert(isPalindrome(0)==true);
	assert(isPalindrome(-1)== false);
	assert(isPalindrome(121)==true);
	assert(isPalindrome(-121) == false);
	assert(isPalindrome(12) == false);
	printf("ok No 7\r\n");
	return EXIT_SUCCESS;
}