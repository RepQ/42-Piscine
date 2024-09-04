/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: santi <santi@itb>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 22:35:01 by santi             #+#    #+#             */
/*   Updated: 2024/09/03 01:20:45 by santi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int				start;
	int				end;
	long long int	mid;

	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (nb);
	start = 1;
	end = nb / 2;
	while (start <= end)
	{
		mid = (end + start) / 2;
		if (mid * mid < nb)
		{
			start = mid + 1;
		}
		else if (mid * mid > nb)
		{
			end = mid - 1;
		}
		else
			return (mid);
	}
	return (0);
}
