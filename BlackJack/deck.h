//
// Created by Arina on 15.12.2021.
//

#ifndef BLACKJACK_DECK_H
#define BLACKJACK_DECK_H

#include "cards.h"

void init_deck(card_t *cards[]);
void shuffle(card_t *cards[]);
void show_deck(card_t* cards[]);
void destroy(card_t *cards[]);

#endif //BLACKJACK_DECK_H
