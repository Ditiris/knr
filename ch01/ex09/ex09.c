#include <stdio.h>

#define CHAR_BLANK ' '

int main() {
	
	char c;

	short found_blank = 0;

	while ((c = getchar()) != EOF) {
		if (c == CHAR_BLANK) {
			if (found_blank != 1) {
				found_blank = 1;
				putchar(c);
			}
		} else {
			found_blank = 0;
			putchar(c);
		}
	}
	printf("\n");
}
