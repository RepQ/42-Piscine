/* ************************************************************************** */
/*                                                                            */
/*                                              ######   #######   ######     */
/*   ft_convert_base.c                            ##        #      #     #    */
/*                                                ##        #      #     #    */
/*   By: santi <santi@itb>                        ##        #      #######    */
/*                                                ##        #      #     #    */
/*   Created: 2024/09/11 19:50:18 by santi        ##        #      #     #    */
/*   Updated: 2024/09/15 00:23:58 by santi      ######      #      ######     */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa(int nbr, char *base_to);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
int		check_base_from(char *nbr, char *base_from, int init);
int		check_nbr_sign(char *nbr);
int		valid_base(char *base);
int		ft_atoi(char *nbr, char *base_from);

int	valid_base(char *base)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (base[i])
		i++;
	if (i <= 1)
		return (0);
	while (base[j])
	{
		if (base[j] == '+' || base[j] == '-' || base[j] == ' '\
			|| (base[j] >= 9 && base[j] <= 13))
			return (0);
		else if (base[j + 1] && base[j] == base[j + 1])
			return (0);
		j++;
	}
	return (i);
}

int	check_nbr_sign(char *nbr)
{
	int	sign;
	int	i;

	sign = 1;
	i = 0;
	while (nbr[i])
	{
		if (nbr[i] == ' ' || (nbr[i] >= 9 && nbr[i] <= 13))
			i++;
		else if (nbr[i] == '-')
		{
			sign *= -1;
			i++;
		}
		else
			return (i * sign);
	}
	return (i);
}

int	check_base_from(char *nbr, char *base_from, int init)
{
	int	i;
	int	found;
	int	j;

	i = init;
	while (nbr[init])
	{
		j = -1;
		found = 0;
		while (base_from[++j])
			if (nbr[i] == base_from[j])
				found = 1;
		if (!found)
			return (i);
		i++;
	}
	return (i);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*convert;

	if (!valid_base(base_from) || !valid_base(base_to))
		return (0);
	convert = ft_itoa(ft_atoi(nbr, base_from), base_to);
	if (!convert)
		return (0);
	return (convert);
}
/*
int	main(void)
{
	char	nbr[] = "-255";
	char	base_from[] = "0123456789ABCDEF";
	char	base_to[] = "01";

	printf("%s\n", ft_convert_base(nbr, base_from, base_to));
}
*/
