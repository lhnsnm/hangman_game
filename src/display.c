#include <stdlib.h>
#include <stdio.h>
#include "../include/display.h"

void display_word(const char guess_word[])
{
    printf("Word: ");

    for (size_t i = 0; guess_word[i] != '\0'; i++)
    {
        printf("%c ", guess_word[i]);
    }

    printf("\n");
}

void draw_hangman(int attempt)
{
    const char *hangman_limbs[] = {
        "      __________",
        "     |          |",
        "     |          0",
        "     |         /|\\",
        "     |         / \\",
        "_____|______________"};

    printf("\n");

    for (int i = 0; i <= attempt && i < 6; i++)
    {
        printf("%s\n", hangman_limbs[i]);
    }
}