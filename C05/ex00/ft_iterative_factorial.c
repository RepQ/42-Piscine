/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: santi <santi@itb>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:54:31 by santi             #+#    #+#             */
/*   Updated: 2024/09/02 21:00:05 by santi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	a;

	if (nb < 0)
		return (0);
	a = 1;
	while (nb > 0)
	{
		a *= nb;
		nb--;
	}
	return (a);
}
