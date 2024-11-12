/*
** EPITECH PROJECT, 2024
** my_strcpy
** File description:
** Copy n letter of a string into another
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    for (int count = 0; count < n; count++) {
        dest[count] = src[count];
    }
    return dest;
}
