#include <stdio.h>
#include <stdlib.h>

// Initializing shared resources
int mutex = 1; // Mutex for mutual exclusion
int full = 0;  // Count of filled buffer slots
int empty; // Count of empty buffer slots
int x = 0;  
int n;   // Counter for produced items

// Producer function to add an item to the buffer
void producer() {
    --mutex; // Lock the critical section
    --empty; // Decrease empty slot count
    x++; // Increase produced item count
    
    printf("Producer produces item %d\n", x);
    ++full; // Increase filled slot count
    ++mutex; // Unlock the critical section
}

// Consumer function to remove an item from the buffer
void consumer() {
    --mutex; // Lock the critical section
    --full; // Decrease filled slot count
    printf("Consumer consumes item %d\n", x);
    x--; // Decrease produced item count
    ++empty; // Increase empty slot count
    ++mutex; // Unlock the critical section
}

// Main function to drive the producer-consumer process
int main() {
    int choice;
    
        // Display menu options
        printf("Enter the size of the buffer:");
        scanf("%d", &empty);
        while (1) {
        printf("\nChoose an operation:\n");
        printf("1) Producer\n");
        printf("2) Consumer\n");
        printf("3) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Switch case to handle user choice
        switch (choice) {
            case 1:
                // Check if buffer has space for production
                if (mutex == 1 && empty != 0)
                    producer();
                else
                   
                    printf("Buffer is full!\n");
                break;
            case 2:
                // Check if buffer has items for consumption
                if (mutex == 1 && full != 0)
                    consumer();
                else
                    printf("Buffer is empty!\n");
                break;
            case 3:
                // Exit the program
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
