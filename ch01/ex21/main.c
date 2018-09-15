#include <stdio.h>
#define MAXLINE 1000 	/* maximum input line size */
#define HORIZONTAL_TAB 0x09
#define SPACE          0x20
#define SPACES_PER_TAB 4


int my_getline(char line[], int maxline);
void entab(char line[], int len, int spaces);

/* print lines without whitespace */
int main()
{
	int len;				/* current line length */
	char line[MAXLINE];		/* current input line */

	while ((len = my_getline(line, MAXLINE)) > 0) {
		entab(line, len, SPACES_PER_TAB);
	}
	return 0;
}

/* getline: read a line into s, return length */
int my_getline(char s[], int lim)
{
	int c, i;

	for (i=0; i < lim-1 && (c=getchar()) != EOF && c!= '\n'; ++i) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* entab: Replace spaces at beginning of line with tabs */
void entab(char line[], int len, int spaces)
{
	int i;
	int myCharIndex = 0;
	int myNumSpaces = 0;
	int myNumTabs = 0;
	while (myCharIndex < len && (line[myCharIndex] == HORIZONTAL_TAB || line[myCharIndex] == SPACE)) {
		if (line[myCharIndex] == HORIZONTAL_TAB) {
			myNumSpaces += spaces;
		} else if (line[myCharIndex] == SPACE) {
			myNumSpaces++;
		} else {
			break;
		}
		myCharIndex++;
	}
	for (i=0; i < (myNumSpaces/SPACES_PER_TAB); i++) {
		printf("\t");
	}
	for (i=0; i < (myNumSpaces%SPACES_PER_TAB); i++) {
		printf(" ");
	}
	printf("%s", line+myCharIndex);
}