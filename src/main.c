#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#include "../include/display.h"
#include "../include/helper.h"
#include "../include/words.h"

#define MAX_ATTEMPT 6

int main()
{
    WordHint word_list[MAX_WORDS];
    int word_list_count = load_words(word_list);

    if (word_list_count == 0)
    {
        puts("Failed to load words or file empty.");
        return 1;
    }

    srand(time(NULL));

    int secret_word_idx = rand() % word_list_count;

    const char *secret_word = word_list[secret_word_idx].word;
    const char *hint = word_list[secret_word_idx].hint;

    size_t secret_word_len = strlen(secret_word);

    char guess_word[secret_word_len + 1];
    memset(guess_word, '_', secret_word_len);
    guess_word[secret_word_len] = '\0';

    bool guess_letters[ALPHABET_SIZE] = {false};

    // Intro message
    puts("Welcome to Hangman!");
    printf("Hint: %s\n", hint);

    int attempt = 0;

    while (attempt < MAX_ATTEMPT)
    {
        printf("\n");
        display_word(guess_word);
        draw_hangman(attempt);

        char guess = read_guess();

        if (guess == '\0')
            continue;
        if (!is_valid_guess(guess))
            continue;
        if (!mark_guess(guess_letters, guess))
            continue;

        bool found = reveal_guess(
            secret_word_len,
            guess_word,
            secret_word,
            guess);

        if (found)
        {
            puts("Good guess!");
        }
        else
        {
            printf("Sorry, the letter '%c' is not in the word.\n", guess);
            attempt++;
        }

        if (strcmp(secret_word, guess_word) == 0)
        {
            display_word(guess_word);
            printf("Congratulations! You've guessed the word: %s!\n", secret_word);
            break;
        }
    }

    if (attempt >= MAX_ATTEMPT)
    {
        draw_hangman(attempt);
        puts("Sorry, you've run out of chances. The man... is dead!");
        printf("The word was: %s\n", secret_word);
    }

    return 0;
}
