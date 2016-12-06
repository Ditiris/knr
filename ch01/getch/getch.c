#include <stdio.h>

int main()
{
	int c;
	char d;
	while ((c = getchar()) != EOF) {
		d = (c == EOF);
		printf("%d", d);	
	}
	d = (c == EOF);
	printf("%d\n", d);
}
