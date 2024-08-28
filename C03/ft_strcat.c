#include <stdio.h>
#include <stdlib.h>

char    *ft_strcat(char *dest, char *src);

char    *ft_strcat(char *dest, char *src)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (dest[i])
    {
        i++;
    }
    while (src[j])
    {
        dest[i] = src[j];
        j++;
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

int main(int argc, char **argv)
{
    argc += 0;
    char    str1[15] = "Hola Mundo";
        printf("%s\n", str1);
    printf("%s\n", ft_strcat(str1, argv[1]));
    printf("%s\n", str1);
}