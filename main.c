#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rules() {
    printf("\n\t\t\t\t ROCK - PAPER - SCISSORS \t\t\t\t\n");
    printf("Rules:\n");
    printf("1. Rock  vs Scissors -> Rock wins\n");
    printf("2. Paper vs Rock     -> Paper wins\n");
    printf("3. Scissors vs Paper -> Scissors wins\n");
    printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
}

int main() {
    int userChoice, computerChoice;
    int userScore=0, compScore=0, round=1;
    char playAgain;
    srand(time(0)); // Seed for random number generation
    rules();
    do {
        printf("\n--------- ROUND %d ---------\n", round);
        printf("Enter your choice:\n");
        printf("1. Rock\n2. Paper\n3. Scissors\n");
        printf("Your move: ");
        scanf("%d", &userChoice);
        if (userChoice<1||userChoice>3)
        {
            printf("Invalid choice! Please choose a number between 1-3.\n");
            continue;
        }
        computerChoice=(rand()%3)+1; // Random number 1–3
        // Display choices
        char *moves[]={"", "Rock", "Paper", "Scissors"};
        printf("You chose: %s\n", moves[userChoice]);
        printf("Computer chose: %s\n", moves[computerChoice]);
        // Decide winner
        if (userChoice == computerChoice)
        {
            printf("Result: It's a Draw!\n");
        } else if ((userChoice==1&&computerChoice==3)||
                   (userChoice==2&&computerChoice==1)||
                   (userChoice==3&&computerChoice==2))
        {
            printf("Result: You WIN this round!\n");
            userScore++;
        } else
        {
            printf("Result: Computer WINS this round!\n");
            compScore++;
        }
        printf("Score = You: %d | Computer: %d\n",userScore,compScore);

        printf("\nDo you want to play another round? (y/n): ");
        scanf(" %c",&playAgain);
        round++;
    } while (playAgain=='y'||playAgain=='Y');

    printf("\n\t\t\t\t FINAL RESULT \t\t\t\t\n");
    if (userScore > compScore)
        printf(" Congratulations! You are the Champion!\n");
    else if (userScore < compScore)
        printf(" Computer wins the game! Try again.\n");
    else
        printf(" It's a TIE!\n");

    printf("Final Score = You: %d | Computer: %d\n", userScore, compScore);
    printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");

    return 0;
}
