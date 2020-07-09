#include "head.h"

int my_snprintf(char s[100], size_t n, char *format, ... )
{
	int i = 0;
	char tmp[2];
	va_list arg;
	va_start(arg, format);
	int count = 0;
	char s11[100];
	s11[0]  = '\0';
	while (format[i] && format[i + 1])
	{
		tmp[0] = format[i];
		if (format[i] == '%' && format[i + 1] == 's')
		{
//			printf("%s", va_arg(arg, char*));
//			printf("%s", va_arg(arg, char*));
			strcat(s11, va_arg(arg, char*));
			i++;
		}
		else
			strcat(s11, tmp);
		i++;
		count++;
	}

	int len = strlen(s11);
//	printf("||%s||", s11);
	if (len > count)
		strncpy(s, s11, n - 1);
	else
		strcpy(s, s11);
	va_end(arg);
	return len;
}
