/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: santi <santi@itb>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 14:50:55 by santi             #+#    #+#             */
/*   Updated: 2024/08/31 20:54:33 by santi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

int	ft_strlen(char *s1)
{
	int	i;

	i = 0;
	while (s1[i])
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	char			*copy;
	unsigned int	needle_len;

	if (!to_find || ft_strlen(to_find) == 0)
		return (str);
	copy = str;
	needle_len = ft_strlen(to_find);
	while (*copy)
	{
		if (!ft_strncmp(copy, to_find, needle_len))
			return (copy);
		copy++;
	}
	return (0);
}
