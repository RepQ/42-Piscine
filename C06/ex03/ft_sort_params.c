/* ************************************************************************** */
/*                                                                            */
/*                                              ######   #######   ######     */
/*   ft_sort_params.c                             ##        #      #     #    */
/*                                                ##        #      #     #    */
/*   By: santi <santi@itb>                        ##        #      #######    */
/*                                                ##        #      #     #    */
/*   Created: 2024/09/06 17:57:21 by santi        ##        #      #     #    */
/*   Updated: 2024/09/06 20:18:22 by santi      ######      #      ######     */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

void	ft_swap(char **src, char **dst)
{
	char	*aux;

	aux = *src;
	*src = *dst;
	*dst = aux;
	aux += 0;
}

void	ft_print_params(char **params)
{
	int	i;
	int	j;

	i = 1;
	while (params[i])
	{
		j = 0;
		while (params[i][j])
		{
			write(1, &params[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

char	**ft_sort_params(char **argv)
{
	char	**aux_argv;
	int		i;
	int		j;

	aux_argv = argv;
	i = 1;
	while (aux_argv[i])
	{
		j = i + 1;
		while (aux_argv[j])
		{
			if (ft_strcmp(aux_argv[i], aux_argv[j]) > 0)
			{
				ft_swap(&aux_argv[i], &aux_argv[j]);
			}
			j++;
		}
		i++;
	}
	return (aux_argv);
}

int	main(int argc, char **argv)
{
	if (argc > 0)
		ft_print_params(ft_sort_params(argv));
	return (0);
}
