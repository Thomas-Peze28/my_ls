/*
** EPITECH PROJECT, 2024
** my_str_concat
** File description:
** Concat 2 string
*/
#include <stdlib.h>
#include "my.h"

char *my_str_concat(char *dest, char *src)
{
    char *result = malloc(my_strlen(src) + my_strlen(dest) + 1);
    int i = 0;
    int j = 0;

    while (dest[i] != '\0') {
        result[i] = dest[i];
        i++;
    }
    while (src[j] != '\0') {
        result[i] = src[j];
        i++;
        j++;
    }
    result[i] = '\0';
    return result;
}
