#include <stdio.h>
#include "game.h"

int main() {
    printf("Welcome to Blackjack!!\n");
    printf("Enter your name\n");
    char name[10] = "";
    scanf("%s", name);
    printf("Hello %s ! Let's play? Type 'y' if ready or 'n' if you wanna exit \n", name);
    char flag;
    scanf("%s", &flag);
    if (flag == 'y' || flag == 'Y') {
        start_game(name);
    } else {
        printf("Good buy! \n");
        return 0;
    }
    return 0;
}
