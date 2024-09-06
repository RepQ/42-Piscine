/* ************************************************************************** */
/*                                                                            */
/*                                              ######   #######   ######     */
/*   ft_print_params.c                            ##        #      #     #    */
/*                                                ##        #      #     #    */
/*   By: santi <santi@itb>                        ##        #      #######    */
/*                                                ##        #      #     #    */
/*   Created: 2024/09/06 15:38:12 by santi        ##        #      #     #    */
/*   Updated: 2024/09/06 16:52:12 by santi      ######      #      ######     */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc > 0)
		ft_print(argv);
	return (0);
}
