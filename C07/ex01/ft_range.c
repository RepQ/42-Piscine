/* ************************************************************************** */
/*                                                                            */
/*                                              ######   #######   ######     */
/*   ft_range.c                                   ##        #      #     #    */
/*                                                ##        #      #     #    */
/*   By: santi <santi@itb>                        ##        #      #######    */
/*                                                ##        #      #     #    */
/*   Created: 2024/09/09 14:08:44 by santi        ##        #      #     #    */
/*   Updated: 2024/09/09 14:41:09 by santi      ######      #      ######     */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max);

int	*ft_range(int min, int max)
{
	int	len;
	int	*new;
	int	i;

	if ((max - min) <= 0)
		return (0);
	len = max - min;
	new = (int *)malloc((sizeof(int) * len));
	if (!new)
		return (0);
	i = -1;
	while (++i < len)
		new[i] = min + i;
	return (new);
}
