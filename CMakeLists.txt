cmake_minimum_required(VERSION 3.20)
project(blackjack C)

set(CMAKE_C_STANDARD 11)

add_executable(blackjack main.c cards.h deck.c deck.h game.c game.h)
