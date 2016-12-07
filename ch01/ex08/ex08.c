#include <stdio.h>

#define CHAR_BLANK ' '
#define CHAR_TAB '\t'
#define CHAR_NEWLINE '\n'

int main() {
	
	char c;

	long num_blanks = 0;
	long num_tabs = 0;
	long num_newlines = 0;
	long num_chars = 0;

	while ((c = getchar()) != EOF) {
		++num_chars;
		if (c == CHAR_BLANK) {
			++num_blanks;
		}
		if (c == CHAR_TAB) {
			++num_tabs;
		}
		if (c == CHAR_NEWLINE) {
			++num_newlines;
		}
	}

	printf("Characters: %ld\n", num_chars);
	printf("Blanks:     %ld\n", num_blanks);
	printf("Tabs:       %ld\n", num_tabs);
	printf("Newlines:   %ld\n", num_newlines);
}