/*
** EPITECH PROJECT, 2024
** ls
** File description:
** read dir with hidden files
*/

#include "my.h"
#include "ls.h"

int read_dir_hid(char *path)
{
    DIR *dir;
    struct dirent *info_dir;

    dir = opendir(path);
    if (dir == NULL)
        return 84;
    info_dir = readdir(dir);
    while (info_dir) {
        my_printf("%s", info_dir->d_name);
        info_dir = readdir(dir);
        if (info_dir) {
            my_printf(" ");
        }
    }
    closedir(dir);
    my_printf("\n");
    return 0;
}
