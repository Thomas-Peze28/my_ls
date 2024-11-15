/*
** EPITECH PROJECT, 2024
** my_str_isprintable
** File description:
** Return if string a string is printable
*/

#include "my.h"

char *my_strcat(char *dest, char *src)
{
    int i = my_strlen(dest);
    int j = 0;

    while (src[j] != '\0')
        dest[i] = src[j];
        i++;
        j++;
    dest[i] = '\0';
    return dest;
}
