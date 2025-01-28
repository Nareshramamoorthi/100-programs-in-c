#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate love percentage
int calculateLoveScore(char name1[], char name2[]) {
    if ((strcmp(name1, "Naresh") == 0 && strcmp(name2, "Suba") == 0) ||
        (strcmp(name1, "Suba") == 0 && strcmp(name2, "Naresh") == 0)) {
        return 100; // Special case for Naresh and Suba
    }
    return (rand() % 100) + 1; // Random score between 1 and 100
}

int main() {
    char name1[50], name2[50];
    int loveScore;

    // Seed random number generator
    srand(time(0));

    printf("Enter the first name: ");
    scanf("%s", name1);
    printf("Enter the second name: ");
    scanf("%s", name2);

    loveScore = calculateLoveScore(name1, name2);

    printf("\nLove Meter Result:\n");
    printf("%s ❤️ %s = %d%%\n", name1, name2, loveScore);

    return 0;
}
