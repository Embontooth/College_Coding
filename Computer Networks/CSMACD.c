#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 16
#define SLOT_TIME 51.2 // in microseconds

void csma_cd() {
    int attempt = 0;
    int collision = 0;
    srand(time(NULL));

    while (attempt < MAX_ATTEMPTS) {
        printf("Attempt %d: Listening for carrier...\n", attempt + 1);
        
        // Simulate carrier sensing
        if (rand() % 2 == 0) {
            printf("Carrier detected, waiting...\n");
            collision = 1;
        } else {
            printf("No carrier detected, transmitting...\n");
            collision = 0;
        }

        if (collision) {
            attempt++;
            int backoff_time = (rand() % (1 << attempt)) * SLOT_TIME;
            printf("Collision detected! Backing off for %d microseconds.\n", backoff_time);
            usleep(backoff_time);
        } else {
            printf("Transmission successful!\n");
            break;
        }
    }

    if (attempt == MAX_ATTEMPTS) {
        printf("Max attempts reached. Transmission failed.\n");
    }
}

int main() {
    csma_cd();
    return 0;
}