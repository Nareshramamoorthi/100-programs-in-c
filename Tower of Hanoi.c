#include <stdio.h>

// Recursive function to solve Tower of Hanoi
void towerOfHanoi(int n, char source, char target, char auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, target);
        return;
    }

    // Move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, source, auxiliary, target);

    // Move the nth disk from source to target
    printf("Move disk %d from %c to %c\n", n, source, target);

    // Move n-1 disks from auxiliary to target
    towerOfHanoi(n - 1, auxiliary, target, source);
}

int main() {
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    printf("Steps to solve Tower of Hanoi:\n");
    towerOfHanoi(n, 'A', 'C', 'B'); // A = source, C = target, B = auxiliary

    return 0;
}
