/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** h file
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>

#ifndef MY_
    #define MY_

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char *src);
char *my_str_concat(char *dest, char *src);
char *my_strncat(char *dest, char const *src, int nb);
char **my_str_to_word_array(char const *str);
void my_sort_int_array(int *tab, int size);
int check_lettre(const char *str, int i);
int check_number(const char *str, int i);
int my_getsign(char const *str);
int my_putnbr_base(int nbr, char const *base);
int mini_printf(const char *format, ...);
int fs_open_file(char const *filepath);
void fs_understand_return_of_read(int fd, char *buffer, int size);
void fs_cat_500_bytes(char const *filepath);
void fs_cat_x_bytes(char const *filepath, int x);
int my_putnbr_base(int nbr, char const *base);
double posi(double n);
int nota_sc_e(int dot);
int nota_sc_cont(int dot, int nbcara);
int my_putnbr_e(double n, long pre);
int my_putnbr_sc(double n, long pre);
int my_put_long(unsigned long int nb);
int my_put_float(double n, int pre);
double my_round(double n, int pres);
int my_put_unsigned(long int nb);
int my_printf(const char *format, ...);
char print_type(mode_t mode);
char *print_permissions(mode_t mode);
int read_dir(char *path);
int read_dir_hid(char *path);
int read_file(char *path);
int get_total_blocks(char *path);
int read_dir_files(char *path);
int ls_bs(int ac, char **av);
int my_ls(int ac, char **av);




#endif /* MY_ */
