/* ************************************************************************** */
/*                                                                            */
/*                                              ######   #######   ######     */
/*   ft_rev_params.c                              ##        #      #     #    */
/*                                                ##        #      #     #    */
/*   By: santi <santi@itb>                        ##        #      #######    */
/*                                                ##        #      #     #    */
/*   Created: 2024/09/06 17:37:21 by santi        ##        #      #     #    */
/*   Updated: 2024/09/06 17:42:50 by santi      ######      #      ######     */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_params(int argc, char **argv)
{
	int	i;
	int	j;

	i = argc - 1;
	while (i > 0)
	{
		j = 0;
		while (argv[i][j])
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i--;
	}
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		ft_rev_params(argc, argv);
	return (0);
}
