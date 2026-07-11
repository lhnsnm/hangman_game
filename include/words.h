#ifndef WORDS_H
#define WORDS_H

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50
#define MAX_HINT_LENGTH 100
#define ALPHABET_SIZE 26

typedef struct WordHint
{
    char word[MAX_WORD_LENGTH];
    char hint[MAX_HINT_LENGTH];
} WordHint;

int load_words(WordHint word_list[]);


#endif