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

int ls_bs(int ac, char **av)
{
    char* path = av[1];
    int nbarg = ac;
    
    DIR *dir;
    dir = opendir(path);

    struct dirent *info_dir;
    struct stat info_file;

    printf("%s\n", path);
    printf("%d\n", nbarg);
    
    if (dir != NULL) {
        info_dir = readdir(dir);
        printf("Name : %s\n", info_dir->d_name);
        printf("Type : %d\n", info_dir->d_type);
        printf("Inode : %ld\n", info_dir->d_ino);
        closedir(dir);
    } else {
        printf("Failed to open dir or not a folder\n");
        stat(path, &info_file);
        printf("Inode : %ld\n", info_file.st_ino);
        printf("Major : %ld\n", info_file.st_dev);
        printf("Hard Link : %ld\n", info_file.st_nlink);
        printf("Size : %ld\n", info_file.st_size);
        printf("Allocated space : %ld\n", info_file.st_blocks * 512);
        printf("UID : %d\n", info_file.st_uid);
        printf("GID : %d\n", info_file.st_gid);
    }
    return 0;
}

int read_dir(char* path)
{
    DIR *dir;
    struct dirent *info_dir;
    dir = opendir(path);

    if (dir == NULL)
        return 84;
    info_dir = readdir(dir);
    while(info_dir) {
        if(info_dir->d_name[0] != '.') {
            printf("%s  ", info_dir->d_name);
        }
        info_dir = readdir(dir);
    }
    closedir(dir);
    printf("\n");
    return 0;
}

int ls(int ac, char **av)
{
    if (ac == 1) {
       read_dir("./"); 
       return 0;
    }
    for (int i = 1; i < ac; i++) {
        printf("%s:\n", av[i]);
        read_dir(av[i]);
        if (i != ac-1) {
            printf("\n");
        }
    }
    return 0;
}
