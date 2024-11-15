/*
** EPITECH PROJECT, 2024
** ls
** File description:
** read files informations
*/

#include "my.h"

int read_file(char *path)
{
    struct stat info_file;
    struct passwd *pwd;
    struct group *grp;
    char **time_array;

    stat(path, &info_file);
    time_array = my_str_to_word_array(ctime(&info_file.st_mtime));
    pwd = getpwuid(info_file.st_uid);
    grp = getgrgid(info_file.st_gid);
    my_printf("%c", print_type(info_file.st_mode));
    my_printf("%s ", print_permissions(info_file.st_mode));
    my_printf("%d ", info_file.st_nlink);
    my_printf("%s ", pwd->pw_name);
    my_printf("%s ", grp->gr_name);
    my_printf("%d ", info_file.st_size);
    my_printf("%s %s %s:%s ", time_array[1], time_array[2]
        , time_array[3], time_array[4]);
    return 0;
}

int read_dir_files(char *path)
{
    DIR *dir;
    struct dirent *info_dir;
    char *fullpath = malloc(my_strlen(path));

    my_strcpy(fullpath, path);
    dir = opendir(path);
    if (dir == NULL)
        return 84;
    info_dir = readdir(dir);
    while (info_dir) {
        if (info_dir->d_name[0] != '.') {
            read_file(my_str_concat(fullpath, info_dir->d_name));
            mini_printf("%s\n", info_dir->d_name);
        }
        info_dir = readdir(dir);
    }
    closedir(dir);
    return 0;
}
