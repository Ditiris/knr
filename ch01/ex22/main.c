#include <stdio.h>
#include <string.h>
#define MAXLINE 		1000 	/* maximum input line size */
#define SPACE          	0x20
#define MARGIN 			60


int my_getline(char line[], int maxline);
void fold(char line[], int len, int margin);

/* print lines without whitespace */
int main()
{
	int len;				/* current line length */
	char line[MAXLINE];		/* current input line */

	while ((len = my_getline(line, MAXLINE)) > 0) {
		fold(line, len, MARGIN);
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

/* fold: Fold line of length len at margin (if possible) */
void fold(char line[], int len, int margin)
{
#ifdef DEBUG
	printf("\nTesting line: %s", line);
#endif
	int myFirstIndex = 0;
	int myLastIndex = 0;
	int myCharCount = 0;
	int myLastWhitespaceIndex = 0;
	int i = 0;
	char newline[MAXLINE];
	for (i = 0; i < len; i++) {
		myCharCount++;
		if (line[i] == SPACE) {
			myLastWhitespaceIndex = i;
#ifdef DEBUG
			printf("myLastWhitespaceIndex = %d\n", i);
#endif
		}
		if (i - myFirstIndex == margin) {
			myLastIndex = myLastWhitespaceIndex;
#ifdef DEBUG
			printf("At margin, myFirstIndex=%d, myLastWhitespaceIndex=%d\n", myFirstIndex, myLastWhitespaceIndex);
#endif
			memset(newline, 0, MAXLINE);
			memcpy(newline, line+myFirstIndex, myLastWhitespaceIndex-myFirstIndex);
			printf("%s\n", newline);
			myFirstIndex = myLastWhitespaceIndex+1;
			myCharCount = 0;
		}
	}
	if (myLastWhitespaceIndex != len) {
		memset(newline, 0, MAXLINE);
		memcpy(newline, line+myFirstIndex, len-myFirstIndex);
		printf("%s", newline);
	}
}