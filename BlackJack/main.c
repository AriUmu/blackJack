#include <stdio.h>
#include "game.h"

int main() {
    printf("Welcome to Blackjack!!\n");
    printf("Enter your name\n");
    char name[10] = "";
    scanf("%s", name);
    printf("Hello %s ! Let's play? Type 'y' if ready or 'n' if you wanna exit \n", name);
    char flag[1];
    scanf("%s", flag);
    if (flag[0] == 'y' || flag[0] == 'Y') {
        start_game(name);
    } else {
        printf("Good buy! \n");
        return 0;
    }
    return 0;
}
