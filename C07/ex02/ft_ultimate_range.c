/* ************************************************************************** */
/*                                                                            */
/*                                              ######   #######   ######     */
/*   ft_ultimate_range.c                          ##        #      #     #    */
/*                                                ##        #      #     #    */
/*   By: santi <santi@itb>                        ##        #      #######    */
/*                                                ##        #      #     #    */
/*   Created: 2024/09/09 15:32:12 by santi        ##        #      #     #    */
/*   Updated: 2024/09/09 15:56:44 by santi      ######      #      ######     */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max);

int	ft_ultimate_range(int **range, int min, int max)
{
	int	len;
	int	i;

	if (max - min <= 0)
	{
		*range = 0;
		return (0);
	}
	i = -1;
	len = max - min;
	*range = (int *)malloc(sizeof(int) * len);
	if (!*range)
		return (-1);
	while (++i < len)
		*(*range + i) = min + i;
	return (len);
}
