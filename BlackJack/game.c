//
// Created by Arina on 16.12.2021.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "deck.h"
#include "cards.h"

card_t *cards[52];

typedef struct {
    char name[10];
    card_t card[4];
    int cardsCounter;
} player_t;


void __finish_game(card_t *cards) {
    destroy(cards);
}

static void destroyPlayer(player_t *player) {
    free(player->name);
}

player_t *createNewPlayer(char *playerName, card_t card1, card_t card2) {
    player_t *player = (player_t *) malloc(sizeof(player_t));
    strcmp(player->name, playerName);
    player->card[0] = card1;
    player->card[1] = card2;
    player->cardsCounter = 2;
    return player;
}

static int countCardRank(int amountOfCard, card_t *cards) {
    int result = 0;
    for (int i = 0; i < amountOfCard; ++i) {
        switch (cards[i].rank[0]) {
            case '2':
                result += 2;
                break;
            case '3':
                result += 3;
                break;
            case '4':
                result += 4;
                break;
            case '5':
                result += 5;
                break;
            case '6':
                result += 6;
                break;
            case '7':
                result += 7;
                break;
            case '8':
                result += 8;
                break;
            case '9':
                result += 9;
                break;
            case '0':
                result += 10;
                break;
            case 'J':
                result += 10;
                break;
            case 'Q':
                result += 10;
                break;
            case 'K':
                result += 10;
                break;
            case 'A':
                result += 11;
                break;
        }
    }
    return result;
}

static void show_winner(player_t *player, player_t *dealer) {
    printf("Dealer has the next cards! \n");
    for (int i = 0; i < dealer->cardsCounter; i++) {
        printf("%c%c  \n", dealer->card[i].rank[0], dealer->card[i].rank[1]);
    }

    int playerResult = countCardRank(player->cardsCounter, player->card);
    int dealerResult = countCardRank(dealer->cardsCounter, dealer->card);

    if (playerResult == 21) {
        printf("You won with result %d vs %d \n", playerResult, dealerResult);
    } else if (dealerResult <= 21 && playerResult <= 21 && (playerResult > dealerResult)) {
        printf("You won with result %d vs %d \n", playerResult, dealerResult);
    } else if (dealerResult > 21) {
        printf("You won with result %d vs %d \n", playerResult, dealerResult);
    } else {
        printf("Dealer won with result %d vs %d \n", dealerResult, playerResult);
    }
}

void start_game(char *playerName) {
    init_deck(cards);
    shuffle(cards);

    player_t *dealer = createNewPlayer("Dealer", (card_t) *cards[0], (card_t) *cards[1]);
    player_t *player = createNewPlayer(playerName, (card_t) *cards[2], (card_t) *cards[3]);

    while (1) {
        printf("You have the next cards! \n");
        for (int i = 0; i < player->cardsCounter; i++) {
            printf("%c%c   ", player->card[i].rank[0], player->card[i].rank[1]);
            printf("\n");
        }
        printf("Would you like to add one else? \n");
        char flag;
        scanf("%s", &flag);
        if (flag == 'y' || flag == 'Y') {
            int counter = player->cardsCounter;
            player->card[counter] = (card_t) *cards[counter + dealer->cardsCounter];
            player->cardsCounter++;
        } else {
            printf("Let's show our cards! \n");
            show_winner(player, dealer);
            break;
        }
    }

    destroyPlayer(dealer);
    destroyPlayer(player);
    __finish_game(cards);
}







