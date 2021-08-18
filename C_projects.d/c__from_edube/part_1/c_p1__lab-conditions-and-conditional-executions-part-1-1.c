#include <stdio.h>

int main()
{
	int a = 10;
	if (a <= 9)
		puts("First condition is true");
	if (a == 9)
		puts("Second condition is true");
	if (a ==  9 + 1)
		puts("Third condition is true");
	return 0;
}