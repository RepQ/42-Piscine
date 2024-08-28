#include <unistd.h>

char    Row[3];

void    rush(int x, int y)
{
    int i;
    int j;

    i = 0;

    while (i < y)
    {
        if (i == 0)
        {
            Row[0] = 'A';
            Row[1] = 'B';
            Row[2] = 'C';
        }
        else if (i == (y - 1) && i > 1)
        {
            Row[0] = 'C';
            Row[1] = 'B';
            Row[2] = 'A';
        }
        else
        {
            Row[0] = 'B';
            Row[1] = ' ';
            Row[2] = 'B';
        }
        j = 0;
        while (j < x)
        {
            if (j == 0)
                write(1, &Row[0], 1);
            else if (j == (x - 1))
                write(1, &Row[2], 1);
            else
                write(1, &Row[1], 1);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
}