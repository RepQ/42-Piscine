/* ************************************************************************** */
/*                                                                            */
/*                                              ######   #######   ######     */
/*   ft_strjoin.c                                 ##        #      #     #    */
/*                                                ##        #      #     #    */
/*   By: santi <santi@itb>                        ##        #      #######    */
/*                                                ##        #      #     #    */
/*   Created: 2024/09/09 17:25:12 by santi        ##        #      #     #    */
/*   Updated: 2024/09/09 19:18:30 by santi      ######      #      ######     */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strjoin(int size, char **strs, char *sep);
int		ft_strlen(char *str);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_join(int size, char **strs, char *sep, char *strjoin)
{
	int	i;
	int	j;
	int	sizestr;

	i = -1;
	sizestr = -1;
	while (++i < size)
	{
		j = -1;
		while (*(*(strs + i) + (++j)))
			strjoin[(++sizestr)] = *(*(strs + i) + j);
		j = -1;
		if (i < (size - 1))
		{
			while (*(sep + (++j)))
				strjoin[(++sizestr)] = *(sep + j);
		}
	}
	strjoin[(++sizestr)] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		strjoin_len;
	char	*strjoin;

	if (size <= 0)
	{
		strjoin = (char *)malloc(1);
		if (strjoin)
			*strjoin = '\0';
		return (strjoin);
	}
	strjoin_len = 0;
	i = -1;
	while (++i < size)
		strjoin_len += ft_strlen(*(strs + i));
	strjoin_len += (ft_strlen(sep) * (size - 1));
	strjoin = (char *)malloc((sizeof(char) * strjoin_len) + 1);
	if (!strjoin)
		return (0);
	ft_join(size, strs, sep, strjoin);
	return (strjoin);
}
