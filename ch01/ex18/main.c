#include <stdio.h>
#define MAXLINE 1000 	/* maximum input line size */
#define HORIZONTAL_TAB 	0x9
#define LINE_FEED 		0xA
#define FORM_FEED 		0xC
#define CARRIAGE_RETURN 0xD
#define SPACE 			0x20


int my_getline(char line[], int maxline);
int is_whitespace(char line[], int len);

/* print lines without whitespace */
int main()
{
	int len;				/* current line length */
	char line[MAXLINE];		/* current input line */

	while ((len = my_getline(line, MAXLINE)) > 0) {
		if (!is_whitespace(line, len)) {
			printf("%s", line);
		}
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

/* is_whitespace: return 1 if line contains nothing but whitespace, 0 otherwise */
int is_whitespace(char line[], int len)
{
	int i;
	for (i = 0; i < len; i++) {
		if (line[i] != HORIZONTAL_TAB
			&& line[i] != LINE_FEED
			&& line[i] != FORM_FEED
			&& line[i] != CARRIAGE_RETURN
			&& line[i] != SPACE
		) {
			return 0;
		}
	}
	return 1;
}