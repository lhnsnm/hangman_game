#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#include "../include/helper.h"

char read_guess(void)
{
    char buffer[100];
    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
        return '\0';

    if (buffer[1] != '\n' && buffer[1] != '\0')
    {
        puts("Please enter only one letter.");
        return '\0';
    }

    return tolower(buffer[0]);
}

bool is_valid_guess(char guess)
{
    if (guess < 'a' || guess > 'z')
    {
        puts("Please enter a valid alphabet.");
        return false;
    }
    return true;
}

bool mark_guess(bool letters[], char guess)
{
    if (letters[guess - 'a'])
        return false;
    letters[guess - 'a'] = true;
    return true;
}

bool reveal_guess(size_t len,
                  char guess_word[],
                  const char secret_word[],
                  char guess)
{
    bool found = false;
    for (size_t i = 0; i < len; i++)
    {
        if (secret_word[i] == guess)
        {
            guess_word[i] = guess;
            found = true;
        }
    }

    return found;
}