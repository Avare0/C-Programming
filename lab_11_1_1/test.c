#include "head.h"

int main() {
	char s[100], s1[100];
	s[0] = '\0';
	s1[0] = '\0';
//	printf("my: %d %s, their: %d %s\n", my_snprintf(s, 100, "Hello %s %s", "world"), s, snprintf(s1, 100, "Hello %s %s", "world"), s1);
	s[0] = '\0';
	s1[0] = '\0';
//	printf("1 test: %d\n", my_snprintf(s, 100, "Hello %s", "world", "world1") == snprintf(s1, 100, "Hello %s", "world", "world1") && strcmp(s, s1) == 0);
	s[0] = '\0';
	s1[0] = '\0';
	printf("2 test: %d\n", my_snprintf(s, 100, "Hello %s%s", "world", "world1") == snprintf(s1, 100, "Hello %s%s", "world", "world1") && strcmp(s, s1) == 0);
	s[0] = '\0';
	s1[0] = '\0';
	printf("3 test: %d\n", my_snprintf(s, 100, "Hello %s %s", "world", "world1") == snprintf(s1, 100, "Hello %s %s", "world", "world1") && strcmp(s, s1) == 0);
	s[0] = '\0';
	s1[0] = '\0';
	printf("4 test: %d\n", my_snprintf(s, 100, "Hello %s %s", "world", "world1") == snprintf(s1, 100, "Hello %s %s", "world", "world1") && strcmp(s, s1) == 0);
	s[0] = '\0';
	s1[0] = '\0';
	printf("5 test: %d\n", my_snprintf(s, 100, "Hello %s %s", "world", "world1") == snprintf(s1, 100, "Hello %s %s", "world", "world1") && strcmp(s, s1) == 0);
	s[0] = '\0';
	s1[0] = '\0';
	printf("6 test: %d\n", my_snprintf(s, 100, "Hello %s %s", "world", "world1") == snprintf(s1, 100, "Hello %s %s", "world", "world1") && strcmp(s, s1) == 0);
	
	return EXIT_SUCCESS;
}
