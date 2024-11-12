/*
** EPITECH PROJECT, 2024
** my_str_isprintable
** File description:
** Return if string a string is printable
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    for (int count = 0; count <= my_strlen(src); count++) {
        dest[my_strlen(dest)+count] = src[count];
    }
    return dest;
}
