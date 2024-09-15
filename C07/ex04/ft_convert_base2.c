/* ************************************************************************** */
/*                                                                            */
/*                                              ######   #######   ######     */
/*   ft_convert_base2.c                           ##        #      #     #    */
/*                                                ##        #      #     #    */
/*   By: santi <santi@itb>                        ##        #      #######    */
/*                                                ##        #      #     #    */
/*   Created: 2024/09/14 22:15:13 by santi        ##        #      #     #    */
/*   Updated: 2024/09/15 00:27:40 by santi      ######      #      ######     */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa(int nbr, char *base_to);
int		check_base_from(char *nbr, char *base_from, int init);
int		check_nbr_sign(char *nbr);
int		valid_base(char *base);
int		ft_atoi(char *nbr, char *base_from);
char	*mem_nbr(int nbr, int *i, int *sign, char *base_to);

char	*mem_nbr(int nbr, int *i, int *sign, char *base_to)
{
	char	*to_str;

	if (nbr < 0)
	{
		*sign = *sign * -1;
		*i = *i + 1;
	}
	while (nbr != 0)
	{
		nbr /= valid_base(base_to);
		*i = *i + 1;
	}
	to_str = (char *)malloc((sizeof(char) * *i) + 1);
	if (!to_str)
		return (0);
	return (to_str);
}

char	*ft_itoa(int nbr, char *base_to)
{
	char	*to_str;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	to_str = mem_nbr(nbr, &i, &sign, base_to);
	if (!to_str)
		return (0);
	to_str[i] = '\0';
	while (--i >= 0)
	{
		if (i == 0 && sign < 0)
			to_str[i] = '-';
		else
			to_str[i] = base_to[(nbr * sign % valid_base(base_to))];
		nbr /= valid_base(base_to);
	}
	return (to_str);
}

int	ft_atoi(char *nbr, char *base_from)
{
	int	i;
	int	init;
	int	sign;
	int	end;

	sign = 1;
	i = 0;
	init = check_nbr_sign(nbr);
	if (init < 0)
	{
		init *= -1;
		sign *= -1;
	}
	end = check_base_from(nbr, base_from, init);
	while (init < end)
	{
		i = i * valid_base(base_from) + (nbr[init] - 48);
		init++;
	}
	return (i * sign);
}
