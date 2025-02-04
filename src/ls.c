/*
** EPITECH PROJECT, 2024
** ls
** File description:
** easy version of ls
*/

#include "my.h"
#include "ls.h"

int ls_once(int ac, char *active_flags)
{
    if (ac == 1) {
        read_dir("./");
        return 0;
    }
    if (ac < 4 && active_flags[0] == 'a' && active_flags[1] == 'l') {
        get_total_hid_blocks("./");
        read_dir_hid_files("./");
        return 0;
    }
    if (ac < 3 && active_flags[0] == 'a') {
        read_dir_hid("./");
        return 0;
    }
    if (ac < 3 && active_flags[1] == 'l') {
        get_total_blocks("./");
        read_dir_files("./");
        return 0;
    }
    return 0;
}

int ls_flags(int ac, char **av, char *active_flags, int i)
{
    if (ac > 2 && active_flags[0] == 'a' && active_flags[1] == 'l') {
        read_dir(av[i]);
    }
    if (ac > 2 && active_flags[0] == 'a' && active_flags[1] == '-') {
        read_dir_hid(av[i]);
    }
    if (ac > 2 && active_flags[0] == '-' && active_flags[1] == 'l') {
        get_total_blocks(av[i]);
        read_dir_files(av[i]);
    }
    if (ac > 1 && active_flags[0] == '-' && active_flags[1] == '-') {
        read_dir(av[i]);
    }
    return 0;
}

int my_ls(int ac, char **av)
{
    char active_flags[] = "---";

    if (ac > 1)
        get_flags(av, active_flags);
    ls_once(ac, active_flags);
    for (int i = 1; i < ac; i++) {
        if (opendir(av[i]) == NULL && av[i][0] != '-') {
            is_file_is(av[i]);
        }
        if (ac > 2 && opendir(av[i]) != NULL) {
            my_printf("%s:\n", av[i]);
        }
        ls_flags(ac, av, active_flags, i);
        if (i != ac - 1 && opendir(av[i]) != NULL) {
            my_printf("\n");
        }
    }
    return 0;
}
