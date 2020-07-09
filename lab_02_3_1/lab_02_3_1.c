#include <stdio.h>
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int main()
{
	int a, b, ck;
	
	puts("Input a and b separated by space: ");
	ck = scanf("%d %d", &a, &b);

	if (ck == 2 && a > 0 && b > 0)
	{
		while ((a != 0) && (b != 0))
		{
			if (a > b) 
				a %= b;
			else 
				b %= a;
		};

		printf("%d", a + b);

		return EXIT_SUCCESS;
	}
	else
	{
		printf("Input error\n");

		return EXIT_FAILURE;
	}
}