/*
** EPITECH PROJECT, 2024
** my_str_to_word_array
** File description:
** Split a string into words in array
*/

#include <stdlib.h>
#include "my.h"

int count_word(char const *str, char separator)
{
    int count = 0;
    int word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != separator) {
            count++;
            word = 1;
        } else {
            word = 0;
        }
    }
    return count;
}

int is_separator(char letter, char separator)
{
    return (letter == separator);
}

char *get_word(char const *str, int *i, char separator)
{
    int start = *i;
    int length = 0;
    char *word;

    while (str[*i] == separator && str[*i] != '\0') {
        (*i)++;
    }
    start = *i;
    while (str[*i] != separator && str[*i] != '\0') {
        (*i)++;
        length++;
    }
    word = malloc((length + 1) * sizeof(char));
    for (int j = 0; j < length; j++) {
        word[j] = str[start + j];
    }
    word[length] = '\0';
    return word;
}

char **my_str_to_word_array02(char const *str, char separator)
{
    int word_nbr = count_word(str, separator);
    char **tab = malloc((word_nbr + 1) * sizeof(char *));
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        if (!is_separator(str[i], separator)) {
            tab[j] = get_word(str, &i, separator);
            j++;
        } else {
            i++;
        }
    }
    tab[j] = NULL;
    return tab;
}
