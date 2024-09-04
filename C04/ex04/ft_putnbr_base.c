/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: santi <santi@itb>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 21:11:27 by santi             #+#    #+#             */
/*   Updated: 2024/09/01 22:27:57 by santi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_base(long long nbr, char *str, int base)
{
	char	number;

	if (nbr >= base)
		ft_base(nbr / base, str, base);
	number = str[nbr % base];
	write(1, &number, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long long	number;

	number = nbr;
	if (ft_strlen(base) <= 1)
		return ;
	if (number < 0)
	{
		number *= -1;
		write(1, "-", 1);
	}
	if (!ft_strcmp(base, "0123456789"))
		ft_base(number, "0123456789", 10);
	else if (!ft_strcmp(base, "01"))
		ft_base(number, "01", 2);
	else if (!ft_strcmp(base, "0123456789ABCDEF"))
		ft_base(number, "0123456789ABCDEF", 16);
	else if (!ft_strcmp(base, "poniguay"))
		ft_base(number, "poniguay", 8);
	else
		return ;
}
