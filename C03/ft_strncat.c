#include <stdio.h>

char    *ft_strncat(char *dest, char *src, unsigned int nb);

char    *ft_strncat(char *dest, char *src, unsigned int nb)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (nb > 0)
    {
        while (dest[i])
        {
            i++;
        }
        while (src[j] && i < nb)
        {
            dest[i] = src[j];
            i++;
            j++;
        }
        dest[i] = '\0';
    }
    return (dest);
}