/* ************************************************************************** */
/*                                                                            */
/*                                              ######   #######   ######     */
/*   ft_strdup.c                                  ##        #      #     #    */
/*                                                ##        #      #     #    */
/*   By: santi <santi@itb>                        ##        #      #######    */
/*                                                ##        #      #     #    */
/*   Created: 2024/09/08 23:28:43 by santi        ##        #      #     #    */
/*   Updated: 2024/09/08 23:56:35 by santi      ######      #      ######     */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src);
int		ft_strlen(char *str);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*strdup;
	int		i;

	strdup = (char *)malloc(ft_strlen(src) + 1);
	if (!strdup)
		return (0);
	i = 0;
	while (src[i])
	{
		strdup[i] = src[i];
		i++;
	}
	strdup[i] = '\0';
	return (strdup);
}
