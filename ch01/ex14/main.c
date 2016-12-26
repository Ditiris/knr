#include <stdio.h>
#include <ctype.h>

#define LETTERS_IN_ALPHABET 26
#define MAX_HISTOGRAM 60

int main() {
    
    int i, j = 0;
    char c;
    char is_letter = 0;
    unsigned int total_letters = 0;
    unsigned int max_letters = 0;
    unsigned int letters[LETTERS_IN_ALPHABET];
    float percentage[LETTERS_IN_ALPHABET];
    float normalized[LETTERS_IN_ALPHABET];
    unsigned int i_normalized[LETTERS_IN_ALPHABET];
    
    for (i = 0; i < LETTERS_IN_ALPHABET; i++) {
        letters[i] = 0;
        percentage[i] = 0.0;
        normalized[i] = 0.0;
        i_normalized[i] = 0;
    }
    
    // Read input
    while ((c = getchar()) != EOF) {
        c = tolower(c);
        if (c >= 'a' && c <= 'z') {
            letters[c - 'a']++;
            total_letters++;
        }
    }
    
    // Perform computations
    for (i = 0; i < LETTERS_IN_ALPHABET; i++) {
        percentage[i] = (float)letters[i]/total_letters;
        if (letters[i] > max_letters) {
            max_letters = letters[i];
        }
    }
    for (i = 0; i < LETTERS_IN_ALPHABET; i++) {
        normalized[i] = (float)letters[i]/max_letters;
        i_normalized[i] = (int)(normalized[i] * MAX_HISTOGRAM);
    }
    
    // Draw histogram
    for (i = 0; i < LETTERS_IN_ALPHABET; i++) {
        printf("%c: ", i+'a');
        for (j = 0; j < i_normalized[i]; j++) {
            printf("=");
        }
        printf(" (%d/%1.0f%%)\n", letters[i], percentage[i]*100);
    }
    
}
