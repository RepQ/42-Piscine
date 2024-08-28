#include <stdio.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (*str)
    {
        i++;
        str++;
    }
    return (i);
}

unsigned int    ft_strlcat(char *dest, char *src, unsigned int size)
{
    int cat_size;
    int i;
    char    *init_dest;

    i = 0;
    init_dest = dest;
    cat_size = size - ft_strlen(dest);
    while (i < cat_size - 1)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    dest = init_dest;
}