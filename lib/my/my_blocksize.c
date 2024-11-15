/*
** EPITECH PROJECT, 2024
** ls
** File description:
** return total block size of path
*/

#include "my.h"

int get_total_blocks(char *path)
{
    DIR *dir;
    struct dirent *info_dir;
    struct stat file_stat;
    long total_blocks = 0;

    dir = opendir(path);
    if (dir == NULL) {
        return -84;
    }
    info_dir = readdir(dir);
    while (info_dir) {
        if (info_dir->d_name[0] != '.') {
            stat(my_str_concat(path, info_dir->d_name), &file_stat);
            total_blocks += file_stat.st_blocks;
        }
        info_dir = readdir(dir);
    }
    my_printf("total %d\n", total_blocks / 2);
    return 0;
}
