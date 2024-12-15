#include <stdio.h>
#include <limits.h>

// Function to find the minimum number of multiplications
void matrixChainOrder(int p[], int n) {
    int m[n][n];
    int s[n][n];

    // Initialize the diagonal to 0 (cost of single matrix)
    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    // L is the chain length
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++) {
                int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    s[i][j] = k; // Record the split point
                }
            }
        }
    }

    printf("Minimum number of multiplications is %d\n", m[1][n - 1]);

    // Display the optimal parenthesization
    printf("Optimal Parenthesization: ");
    printOptimalParenthesis(s, 1, n - 1);
    printf("\n");
}

// Helper function to print the parenthesization
void printOptimalParenthesis(int s[][100], int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        printOptimalParenthesis(s, i, s[i][j]);
        printOptimalParenthesis(s, s[i][j] + 1, j);
        printf(")");
    }
}

int main() {
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    int p[n + 1];
    printf("Enter the dimensions of matrices:\n");
    for (int i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
    }

    matrixChainOrder(p, n + 1);

    return 0;
}
