/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: santi <santi@itb>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 22:37:13 by santi             #+#    #+#             */
/*   Updated: 2024/09/02 17:21:02 by santi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str, int init, char *base)
{
	int	i;
	int	j;
	int	found;

	i = init;
	while (str[i])
	{
		j = 0;
		found = 0;
		while (base[j] && !found)
		{
			if (str[i] == base[j])
				found = 1;
			else
				j++;
		}
		if (!found)
			return (i);
		i++;
	}
	return (i - init);
}

int	ft_sign(char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == ' ' || \
			(str[i] >= 9 && str[i] <= 13))
			i++;
		else if (str[i] == '-')
		{
			i++;
			sign *= -1;
		}
		else
			return (sign * i);
	}
	return (-100);
}

int	check_base(char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || \
			(base[i] >= 9 && base[i] <= 13))
			return (-1);
		if (base[i] == base[i + 1] && base[i + 1])
			return (-1);
		i++;
	}
	if (i <= 1)
		return (-1);
	return (i);
}

int	ft_number(char *str, int init, char *base)
{
	int	i;
	int	j;
	int	number;
	int	base_size;

	number = 0;
	i = init;
	while (str[i])
	{
		base_size = 1;
		j = 0;
		while (++j < ft_strlen(str, init, base) - (i - init))
			base_size *= check_base(base);
		j = 0;
		while (base[j] != str[i])
			j++;
		number = number + base_size * j;
		i++;
	}
	return (number);
}

int	ft_atoi_base(char *str, char *base)
{
	int	init;
	int	sign;

	sign = 1;
	init = ft_sign(str);
	if (check_base(base) < 0)
		return (0);
	if (init < 0)
	{
		init *= -1;
		sign *= -1;
	}
	return (sign * ft_number(str, init, base));
}
