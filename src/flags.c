/*
** EPITECH PROJECT, 2024
** ls
** File description:
** easy version of ls
*/

#include "my.h"
#include "ls.h"

int is_content(const char *word, char letter)
{
    int i = 0;

    while (word[i] != '\0') {
        if (word[i] == letter)
            return 1;
        i++;
    }
    return 0;
}

void is_flag(char *av, char *active_flags, char *flags)
{
    if (is_content(av, 'a') == 1)
        active_flags[0] = flags[0];
    if (is_content(av, 'l') == 1)
        active_flags[1] = flags[1];
    if (is_content(av, 'd') == 1)
        active_flags[2] = flags[2];
}

char *get_flags(char **av, char *active_flags)
{
    char flags[] = {'a', 'l', 'd'};
    int i = 0;

    while (av[i] != NULL) {
        if (av[i][0] == '-') {
            is_flag(av[i], active_flags, flags);
        }
        i++;
    }
    return active_flags;
}
