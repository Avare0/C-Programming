#include <stdio.h>
#include <math.h>

int main()
{
	int t;
	int minutes, hours;

	puts("Input time in seconds: ");
	scanf("%d", &t);

	minutes = t / 60;
	hours = minutes / 60;
	minutes -= hours * 60;
	t = t - hours * 3600 - minutes * 60;
	
	printf("Equals to %d hour(s) and %d minutes(s) and %d seconds", hours, minutes, t);
	return 0;
}