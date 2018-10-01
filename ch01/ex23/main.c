#include <stdio.h>
#include <string.h>
#define MAXLINE 				1000 	/* maximum input line size */
#define SPACE          			0x20
#define LINE_FEED				0x0A

/* States for parsing comments */
#define ST_IDLE					0
#define ST_FORWARD_SLASH		1
#define ST_MULTILINE_COMMENT	2
#define ST_SINGLE_QUOTE			3
#define ST_DOUBLE_QUOTE			4


int my_getline(char line[], int maxline);
int rtrim(char line[], int len, char remove);
int remove_comments(char line[], int len, int state);

/* print lines without whitespace */
int main()
{
	int len;				/* current line length */
	char line[MAXLINE];		/* current input line */
	int state = ST_IDLE;	/* current state */

	while ((len = my_getline(line, MAXLINE)) > 0) {
		state = remove_comments(line, len, state);
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

/* rtrim: Right trim characters remove from line, return new length */
int rtrim(char line[], int len, char remove)
{
	int i;
	int hasLineFeed;
	if (line[len-1] == LINE_FEED) {
		hasLineFeed = 1;
		len--;
	} else {
		hasLineFeed = 0;
	}
	for (i = len-1; i >= 0; i--) {
		if (line[i] == remove) {
			line[i] = 0;
			len--;
		} else {
			break;
		}
	}
	if (hasLineFeed != 0) {
		line[len] = LINE_FEED;
		len++;
	}
	return len;
}

/* remove_comments: Removes comments from line based on state */
void remove_comments(char line[], int len, int state)
{

}