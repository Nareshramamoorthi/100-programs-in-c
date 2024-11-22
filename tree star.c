#include <stdio.h>

int main() {
    int height = 10; // Height of the tree

    // Print the tree
    for (int i = 1; i <= height; i++) {
        // Print spaces for alignment
        for (int j = 1; j <= height - i; j++) {
            printf(" ");
        }

        // Print stars for the tree branches
        for (int k = 1; k <= 2 * i - 1; k++) {
            printf("*");
        }

        printf("\n");
    }

    // Print the trunk
    for (int i = 1; i <= height / 3; i++) {
        for (int j = 1; j < height; j++) {
            printf(" ");
        }
        printf("|||\n");
    }

    return 0;
}
