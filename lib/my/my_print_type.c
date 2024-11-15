/*
** EPITECH PROJECT, 2024
** ls
** File description:
** easy version of ls
*/
#include "my.h"

char print_type(mode_t mode)
{
    char type;
    const unsigned int flags[] = {S_IFREG, S_IFDIR, S_IFLNK, S_IFCHR,
        S_IFBLK, S_IFIFO, S_IFSOCK};
    const char symbols[] = {'-', 'd', 'l', 'c', 'b', 'p', 's'};

    for (int i = 0; i < 7; i++) {
        if ((mode & __S_IFMT) == flags[i]) {
            type = symbols[i];
            return type;
        }
    }
    return '?';
}
