cmake_minimum_required(VERSION 3.20)
project(BlackJack C)

set(CMAKE_C_STANDARD 11)

add_executable(BlackJack BlackJack/main.c BlackJack/cards.h BlackJack/deck.c BlackJack/deck.h BlackJack/game.c BlackJack/game.h)
