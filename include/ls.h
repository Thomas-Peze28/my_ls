/*
** EPITECH PROJECT, 2024
** ls.h
** File description:
** h file
*/

#ifndef LS_
    #define LS_

    #include <pwd.h>
    #include <grp.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <dirent.h>
    #include <time.h>

char print_type(mode_t mode);
char *print_permissions(mode_t mode);
int read_dir(char *path);
int read_dir_hid(char *path);
int read_file(char *path);
int get_total_blocks(char *path);
int get_total_hid_blocks(char *path);
int read_dir_files(char *path);
int read_dir_hid_files(char *path);
int ls_bs(int ac, char **av);
int my_ls(int ac, char **av);
int len_array(char **array);
char *file_name(char *path);
int is_file_is(char *path);
int is_content(const char *word, char letter);
void is_flag(char *av, char *active_flags, char *flags);
char *get_flags(char **av, char *active_flags);

#endif /* LS_ */
