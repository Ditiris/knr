#include <stdio.h>
#define MAXLINE 1000 	/* maximum input line size */


int my_getline(char line[], int maxline);
void my_reverse(char line[], int len);

/* print lines without whitespace */
int main()
{
	int len;				/* current line length */
	char line[MAXLINE];		/* current input line */

	while ((len = my_getline(line, MAXLINE)) > 0) {
		my_reverse(line, len);
		printf("%s", line);
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

/* my_reverse: reverses the characters of line in space */
void my_reverse(char line[], int len)
{
	int myFrontIndex;
	int myBackIndex = len-1;
	for (myFrontIndex = 0; myFrontIndex < len/2; myFrontIndex++)
	{
		line[myFrontIndex] ^= line[myBackIndex];
		line[myBackIndex] ^= line[myFrontIndex];
		line[myFrontIndex] ^= line[myBackIndex];
		myBackIndex--;
	}
}