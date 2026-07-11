#ifndef HELPER_H
#define HELPER_H

#include <stdlib.h>

char read_guess(void);
bool is_valid_guess(char guess);
bool mark_guess(bool letters[], char guess);

bool reveal_guess(size_t len,
                  char guess_word[],
                  const char secret_word[],
                  char guess);

#endif