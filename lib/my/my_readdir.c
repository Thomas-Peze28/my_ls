/*
** EPITECH PROJECT, 2024
** ls
** File description:
** read directory
*/

#include "my.h"

int read_dir(char *path)
{
    DIR *dir;
    struct dirent *info_dir;

    dir = opendir(path);
    if (dir == NULL)
        return 84;
    info_dir = readdir(dir);
    while (info_dir) {
        if (info_dir->d_name[0] != '.') {
            my_printf("%s", info_dir->d_name);
        }
        info_dir = readdir(dir);
        if (info_dir && info_dir->d_name[0] != '.') {
            my_printf(" ");
        }
    }
    closedir(dir);
    my_printf("\n");
    return 0;
}
