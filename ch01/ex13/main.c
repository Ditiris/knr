#include <stdio.h>

#define CHAR_BLANK ' '
#define CHAR_TAB '\t'
#define CHAR_NEWLINE '\n'
#define IN_WORD 0
#define NOT_IN_WORD 1
#define LONGEST_WORD 45

int main() {
    
    unsigned int word_count[LONGEST_WORD];
    unsigned int total_words = 0;
    unsigned int normalized;
    int i, j = 0;
    for (i = 0; i < LONGEST_WORD; i++) {
        word_count[i] = 0;
    }
    unsigned int state;
    unsigned int char_count = 0;
    char c;
    unsigned char is_letter = 0;
    unsigned char is_whitespace = 0;
    unsigned int max_word_count = 0;
    float percentage[LONGEST_WORD];
    
    while ((c = getchar()) != EOF) {
        
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c<= 'Z')) {
            is_letter = 1;
        } else {
            is_letter = 0;
        }
        
        if (c == ' ' || c == '\n' || c == '\t') {
            is_whitespace = 1;
        } else {
            is_whitespace = 0;
        }
        
        if (state == IN_WORD) {
            if (is_whitespace) {
                word_count[char_count]++;
                char_count = 0;
                total_words++;
                state = NOT_IN_WORD;
            } else {
                char_count++;
            }
        } else {
            if (is_letter) {
                state = IN_WORD;
                char_count++;
            }
        }
        
    }
    for (i = 0; i < LONGEST_WORD; i++) {
        //		printf("%2d: %d\n", i, word_count[i]);
        if (word_count[i] > max_word_count) {
            max_word_count = word_count[i];
        }
    }
    //	printf("Total words: %d\n", total_words);
    
    for (i = 0; i < LONGEST_WORD; i++) {
        percentage[i] = (float)word_count[i]/total_words;
        printf("%2d: ", i);
        normalized = (int)(((float)word_count[i]/max_word_count)*40);
        for (j = 0; j < normalized; j++) {
            printf("%c", '=');
        }
        printf(" (%d/%1.0f%%)\n", word_count[i], percentage[i]*100);
    }
    
    for (j = 40; j >= 0; j--) {
        for (i = 0; i < 20; i++) {
            normalized = (int)(((float)word_count[i]/max_word_count)*40);
            if (normalized > j) {
                printf("  * ");
            } else {
                printf("    ");
            }
        }
        printf("\n");
    }
    for ( i = 0; i < 20; i++) {
        printf("%3d ", i);
    }
    printf("\n");
}
