/*
** EPITECH PROJECT, 2024
** ls
** File description:
** read files informations
*/

#include "my.h"
#include "ls.h"

int read_file(char *path)
{
    struct stat info_file;
    struct passwd *pwd;
    struct group *grp;
    char **date_array;
    char **time_array;

    stat(path, &info_file);
    date_array = my_str_to_word_array02(ctime(&info_file.st_mtime), ' ');
    time_array = my_str_to_word_array02(date_array[3], ':');
    pwd = getpwuid(info_file.st_uid);
    grp = getgrgid(info_file.st_gid);
    printf("%c", print_type(info_file.st_mode));
    printf("%s ", print_permissions(info_file.st_mode));
    printf("%ld ", info_file.st_nlink);
    printf("%s ", pwd->pw_name);
    printf("%s ", grp->gr_name);
    printf("%ld ", info_file.st_size);
    printf("%s %s %s:%s ", date_array[1], date_array[2],
        time_array[0], time_array[1]);
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
            printf("%s\n", info_dir->d_name);
        }
        info_dir = readdir(dir);
    }
    closedir(dir);
    return 0;
}

int read_dir_hid_files(char *path)
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
        if (info_dir) {
            read_file(my_str_concat(fullpath, info_dir->d_name));
            printf("%s\n", info_dir->d_name);
        }
        info_dir = readdir(dir);
    }
    closedir(dir);
    return 0;
}
