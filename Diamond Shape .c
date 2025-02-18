// Zoho Pattern Question: #include <stdio.h>

int main() { int n = 5, i, j;

// Upper half
for(i = 1; i <= n; i++) {
    for(j = i; j < n; j++)
        printf(" ");
    for(j = 1; j <= (2*i-1); j++)
        printf("*");
    printf("\n");
}

// Lower half
for(i = n-1; i >= 1; i--) {
    for(j = n; j > i; j--)
        printf(" ");
    for(j = 1; j <= (2*i-1); j++)
        printf("*");
    printf("\n");
}

return 0;

}

