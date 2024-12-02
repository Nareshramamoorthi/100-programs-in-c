#include <stdio.h>
#include <unistd.h> // For sleep function

int main() {
    int hours = 0, minutes = 0, seconds = 0;

    printf("Digital Clock Simulation\n");
    printf("Press Ctrl+C to stop the clock.\n");

    while (1) {
        // Clear the screen
        printf("\033[H\033[J");

        // Display the clock
        printf("\n%02d:%02d:%02d\n", hours, minutes, seconds);

        // Increment time
        sleep(1);
        seconds++;

        if (seconds == 60) {
            seconds = 0;
            minutes++;
        }
        if (minutes == 60) {
            minutes = 0;
            hours++;
        }
        if (hours == 24) {
            hours = 0;
        }
    }

    return 0;
}
