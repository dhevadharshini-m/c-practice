#include <stdio.h>
#include <pthread.h>
#include <stdatomic.h>

#define NUM_THREADS 4
#define NUM_INCREMENTS 1000000

_Atomic int counter = 0;  // Shared atomic counter

void* increment(void* arg) {
    for (int i = 0; i < NUM_INCREMENTS; i++) {
        counter++;  // Atomic increment
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, increment, NULL);
    }

    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Final counter value: %d (Expected: %d)\n",
           counter, NUM_THREADS * NUM_INCREMENTS);
    return 0;
}
