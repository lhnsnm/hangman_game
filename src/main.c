#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <errno.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50
#define MAX_HINT_LENGTH 100
#define MAX_ATTEMPT 6
#define ALPHABET_SIZE 26

typedef struct WordHint
{
    char word[MAX_WORD_LENGTH];
    char hint[MAX_HINT_LENGTH];
} WordHint;

void display_word(const char guess_word[]);
void draw_hangman(int attempt);
int load_words(WordHint word_list[]);

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

        char guess;
        printf("Enter a letter: ");
        scanf(" %c", &guess);

        guess = tolower(guess);

        printf("\n");

        if (guess < 'a' || guess > 'z')
        {
            puts("Please enter a valid alphabet.");
            continue;
        }

        if (guess_letters[guess - 'a'])
        {
            puts("You've already guessed that letter. Try again.");
            continue;
        }

        guess_letters[guess - 'a'] = true;

        bool found = false;

        for (size_t i = 0; i < secret_word_len; i++)
        {
            if (secret_word[i] == guess)
            {
                guess_word[i] = guess;
                found = true;
            }
        }

        if (found)
            puts("Good guess!");
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

void display_word(const char guess_word[])
{
    printf("Word: ");

    for (int i = 0; guess_word[i] != '\0'; i++)
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

int load_words(WordHint word_list[])
{
    FILE *fp = fopen("./data/words.txt", "r");

    if (fp == NULL)
    {
        perror("fopen");
        return 0;
    }

    char line[256];
    int word_count = 0;

    while (fgets(line, sizeof(line), fp) != NULL && word_count < MAX_WORDS)
    {
        if (sscanf(line, "%49[^|]|%99[^\n]",
                   word_list[word_count].word,
                   word_list[word_count].hint) == 2)
            word_count++;
    }
    fclose(fp);
    return word_count;
}