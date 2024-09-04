/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: santi <santi@itb>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:21:57 by santi             #+#    #+#             */
/*   Updated: 2024/09/04 21:05:25 by santi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	is_safe(int table[10][10], int row, int col)
{
	int	k;
	int	h;
	int	j;
	int	i;

	k = -1;
	h = -1;
	while (++k < 10)
		if (table[row][k] || table[k][col])
			return (0);
	k = row;
	h = col;
	j = -1;
	i = -1;
	while ((k - (++i)) >= 0 && (h - (++j)) >= 0)
		if (table[k - i][h - j])
			return (0);
	i = -1;
	j = -1;
	while ((k + (++i)) <= 9 && (h - (++j)) >= 0)
		if (table[k + i][h - j])
			return (0);
	return (1);
}

void	ft_printf(int table[10][10])
{
	int		i;
	int		j;
	char	pos;

	j = -1;
	while (++j < 10)
	{
		i = -1;
		while (++i < 10)
		{
			if (table[i][j])
			{
				pos = i + 48;
				write(1, &pos, 1);
			}
		}
	}
	write(1, "\n", 1);
}

int	put_queens(int table[10][10], int queen)
{
	int			row;
	static int	counter;

	if (queen >= 10)
	{
		counter++;
		ft_printf(table);
		return (1);
	}
	row = 0;
	while (row < 10)
	{
		if (is_safe(table, row, queen))
		{
			table[row][queen] = 1;
			put_queens(table, queen + 1);
			table[row][queen] = 0;
		}
		row++;
	}
	return (counter);
}

void	ft_preset(int table[10][10])
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			table[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	table[10][10];
	int	queens;

	queens = 0;
	ft_preset(table);
	return (put_queens(table, queens));
}
