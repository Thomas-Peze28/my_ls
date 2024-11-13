/*
** EPITECH PROJECT, 2024
** ls
** File description:
** easy version of ls
*/
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>
#include "include/my.h"
#include <time.h>
#include <pwd.h>

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
            mini_printf("%s  ", info_dir->d_name);
        }
        info_dir = readdir(dir);
    }
    closedir(dir);
    mini_printf("\n");
    return 0;
}

int read_dir_hid(char *path)
{
    DIR *dir;
    struct dirent *info_dir;

    dir = opendir(path);
    if (dir == NULL)
        return 84;
    info_dir = readdir(dir);
    while (info_dir) {
        mini_printf("%s  ", info_dir->d_name);
        info_dir = readdir(dir);
    }
    closedir(dir);
    mini_printf("\n");
    return 0;
}

int my_ls(int ac, char **av)
{
    if (ac == 1) {
        read_dir("./");
        return 0;
    }
    for (int i = 1; i < ac; i++) {
        mini_printf("%s:\n", av[i]);
        read_dir(av[i]);
        if (i != ac - 1) {
            mini_printf("\n");
        }
    }
    return 0;
}
