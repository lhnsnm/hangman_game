#include <stdio.h>
#include "../include/words.h"

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