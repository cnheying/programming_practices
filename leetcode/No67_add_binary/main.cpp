#include <cstdlib>
char* addBinary(char* a, char* b) {
	char* a2 = a;
	char* b2 = b;
	while (*a2)
	{
		a2++;
	}
	a2--;
	while (*b2)
	{
		b2++;
	}
	b2--;
	int acc = 0;
	char ss_tmp[100];
	int i = 0;
	while (a2 >= a || b2 >= b)
	{
		int sum = 0;
		if (a2 >= a) {
			if (*a2 == '1') {
				sum += 1;
			}
			a2--;
		}
		if (b2 >= b) {
			if (*b2 == '1') {
				sum += 1;
			}
			b2--;
		}
		if (acc > 0) {
			sum += 1;
			acc = 0;
		}
		if (sum >= 2)
		{
			acc = 1;
			sum &= 0x01;
		}
		ss_tmp[i] = sum + '0';
		i++;
	}
	if (acc>0) {
		ss_tmp[i] = '1';
		i++;
	}
	char* ps = (char*)calloc(i + 1, sizeof(char));
	int j = 0;
	i--;
	while (i >= 0)
	{
		ps[j] = ss_tmp[i];
		i--;
		j++;
	}
	return ps;
}
#include <cassert>
#include <cstdio>
#include <cstring>
int main(char* argv, int argc) {
	assert(strcmp(addBinary("000","0"),"0"));
	assert(strcmp(addBinary("1", "1"), "10"));
	assert(strcmp(addBinary("111", "1"), "1000"));
	printf("ok No 67\r\n");
	return EXIT_SUCCESS;
}