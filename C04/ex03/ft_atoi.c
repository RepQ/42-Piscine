/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: santi <santi@itb>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 20:05:27 by santi             #+#    #+#             */
/*   Updated: 2024/09/01 20:36:31 by santi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_number(char *str, int init)
{
	int	i;
	int	number;

	number = 0;
	i = init;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (number);
		number = number * 10 + str[i] - '0';
		i++;
	}
	return (number);
}

int	ft_atoi(char *str)
{
	int	init;
	int	sign;

	sign = 1;
	init = ft_sign(str);
	if (init < 0)
	{
		init *= -1;
		sign *= -1;
	}
	return (sign * ft_number(str, init));
}
