#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int userSeed;
int sides;
int ARR_SIZE = 20;
int customRands[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};

int main() {
    int again = 0;

    printf("Please enter a random seed index: ");
    scanf("%d", &userSeed);
    userSeed %= ARR_SIZE;
    
    printf("Please enter the number of sides on the die: ");
    scanf("%d", &sides);

    while(1) {
        printf("Rand number in custom rands at index %d is %d\n", userSeed, customRands[userSeed]);
        printf("The die result is: %d\n", (customRands[userSeed] % sides) + 1);
        printf("Would you like another number? (1 for yes, 0 for no): ");
        scanf("%d", &again);
        if(again == 0) {
            break;
        }
        userSeed++;
        userSeed %= ARR_SIZE;
    }

    return 0;
}
