//
// Created by Arina  on 15.12.2021.
//

#include <stdlib.h>
#include <printf.h>
#include <stdio.h>
#include "cards.h"

/*
 * А - 1 или 11
 * 2 = 2 .... 10 = 10
 * J = Q = K = 10
 */

const char RANKS[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K'};
const char SUITS[4] = {'c', 'd', 'h', 's'};

void init_deck(card_t *cards[]) {
    int count = 0;
    for (int i = 0; i < sizeof(RANKS); i++) {
        for (int j = 0; j < sizeof(SUITS); j++) {
            card_t *card_entity = (card_t *) malloc(sizeof(card_t));
            card_entity->rank[0] = RANKS[i];
            card_entity->rank[1] = SUITS[j];
            cards[count] = card_entity;
            count++;
        }
    }
}

void shuffle(card_t *cards[]) {
    srand(time(NULL));
    for (int i = 0; i < 52; i++) {
        int random = rand() % 51;
        char temp[2];
        temp[0] = cards[random]->rank[0];
        cards[random]->rank[0] = cards[i]->rank[0];
        cards[i]->rank[0] = temp[0];
        //printf("%c%c  \n", cards[i]->rank[0], cards[i]->rank[1]);
    }
}

void show_deck(card_t *cards[]) {
    printf("All deck \n");
    for (int i = 0; i < 52; i++) {
        printf("%c%c  \n", cards[i]->rank[0], cards[i]->rank[1]);
    }
}

void destroy(card_t *cards[]) {
    for (int i = 0; i < 52; i++) {
        free(cards[i]->rank);
    }
}
