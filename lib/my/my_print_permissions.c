/*
** EPITECH PROJECT, 2024
** ls
** File description:
** easy version of ls
*/
#include "my.h"

char *print_permissions(mode_t mode)
{
    char *perms = malloc(10);
    int flags[] = {S_IRUSR, S_IWUSR, S_IXUSR, S_IRGRP, S_IWGRP, S_IXGRP
        , S_IROTH, S_IWOTH, S_IXOTH};
    char symbols[] = {'r', 'w', 'x'};

    my_strcpy(perms, "---------");
    for (int i = 0; i < 9; i++) {
        if (mode & flags[i]) {
            perms[i] = symbols[i % 3];
        } else {
            perms[i] = '-';
        }
    }
    return perms;
}
