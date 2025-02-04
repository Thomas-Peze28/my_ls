/*
** EPITECH PROJECT, 2024
** ls
** File description:
** read directory
*/

#include "my.h"
#include "ls.h"

int len_array(char **array)
{
    int i = 0;
    int count = 0;

    while (array[i] != NULL) {
        count++;
        i++;
    }
    return count - 1;
}

char *file_name(char *path)
{
    char **path_slice = my_str_to_word_array02(path, '/');

    return path_slice[len_array(path_slice)];
}

int is_file_is(char *path)
{
    struct stat file_info;

    if (stat(path, &file_info) == -1) {
        printf("my_ls: cannot access '%s': No such file or directory\n",
            file_name(path));
        return 84;
    }
    my_printf("%s\n", file_name(path));
    return 0;
}
