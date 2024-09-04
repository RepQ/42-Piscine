/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: santi <santi@itb>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:34:02 by santi             #+#    #+#             */
/*   Updated: 2024/09/03 21:55:27 by santi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	int	i;
	int	j;
	int	prime;

	prime = 0;
	j = nb;
	if (j < 2)
		return (2);
	while (prime == 0)
	{
		i = 2;
		prime = 1;
		while (i <= j / i)
		{
			if (j % i == 0)
				prime = -1;
			i++;
		}
		if (prime < 0)
			prime = 0;
		if (prime == 1)
			prime = j;
		j++;
	}
	return (prime);
}
