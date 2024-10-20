#include <stdio.h>
#include <string.h>

// Function to reverse a portion of the string (from start to end)
void reverseWord(char *start, char *end) {
    char temp;
    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

// Function to reverse each word in the sentence
void reverseEachWord(char *sentence) {
    char *wordStart = NULL;
    char *temp = sentence;

    while (*temp) {
        // Mark the beginning of a word
        if (wordStart == NULL && *temp != ' ') {
            wordStart = temp;
        }

        // When we reach a space or end of the string, reverse the word
        if (wordStart && (*temp == ' ' || *(temp + 1) == '\0')) {
            if (*temp == ' ') {
                reverseWord(wordStart, temp - 1);
            } else {
                reverseWord(wordStart, temp);
            }
            wordStart = NULL;
        }
        temp++;
    }
}

int main() {
    char sentence[100];

    // Input the sentence
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Remove the newline character from fgets if present
    sentence[strcspn(sentence, "\n")] = 0;

    reverseEachWord(sentence);

    printf("Sentence with each word reversed: %s\n", sentence);

    return 0;
}
