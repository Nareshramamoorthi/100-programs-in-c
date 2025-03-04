#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int maxArea(int heights[], int n) {
    int stack[MAX], top = -1;
    int maxArea = 0, i = 0;

    while (i < n) {
        if (top == -1 || heights[stack[top]] <= heights[i]) {
            stack[++top] = i++;
        } else {
            int h = heights[stack[top--]];
            int width = (top == -1) ? i : (i - stack[top] - 1);
            int area = h * width;
            if (area > maxArea) maxArea = area;
        }
    }

    while (top != -1) {
        int h = heights[stack[top--]];
        int width = (top == -1) ? i : (i - stack[top] - 1);
        int area = h * width;
        if (area > maxArea) maxArea = area;
    }

    return maxArea;
}

int main() {
    int heights[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(heights) / sizeof(heights[0]);
    
    printf("Largest Rectangle Area: %d\n", maxArea(heights, n));
    return 0;
}
