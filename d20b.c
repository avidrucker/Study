#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int userSeed;
int sides;
int diceInput;
int ARR_SIZE = 20;
int customRands[] = {6, 71, 43, 59, 81, 51, 97, 87, 69, 41, 10, 92, 38, 94, 14, 19, 28, 62, 75, 72};
int rollAgain = 0;
int sameDice = 0;
int sum = 0;
int currentDice;

int main() {
    printf("Please enter a random seed index: ");
    scanf("%d", &userSeed);
    userSeed %= ARR_SIZE;

    while(1) {
        printf("Please enter the number of dice to roll:");
        scanf("%d", &diceInput);

        printf("Please enter the number of sides on the die: ");
        scanf("%d", &sides);

        sameDice = 1;
        while(sameDice) {
            currentDice = diceInput;
            sum = 0;
            while(currentDice > 0) {
                // printf("Rand number in custom rands at index %d is %d\n", userSeed, customRands[userSeed]);
                int currentDieNum = diceInput - currentDice + 1;
                printf("The die result of die %d is: %d\n", currentDieNum, (customRands[userSeed] % sides) + 1);
                sum += (customRands[userSeed] % sides) + 1;
                currentDice--;
                userSeed++;
                userSeed %= ARR_SIZE;
            }
            printf("The sum of the dice is: %d\n", sum);
            printf("Roll same dice again? (1 for yes, 0 for no): ");
            scanf("%d", &sameDice);
            if(sameDice == 0) {
                break;
            }
        }
        
        printf("Roll new dice? (1 for yes, 0 for no): ");
        scanf("%d", &rollAgain);
        if(rollAgain == 0) {
            printf("Bye!");
            break;
        }
    }

    return 0;
}
