/* ************************************************************************** */
/*                                                                            */
/*                                              ######   #######   ######     */
/*   ft_print_program_name.c                      ##        #      #     #    */
/*                                                ##        #      #     #    */
/*   By: santi <santi@itb>                        ##        #      #######    */
/*                                                ##        #      #     #    */
/*   Created: 2024/09/06 14:17:10 by santi        ##        #      #     #    */
/*   Updated: 2024/09/06 14:59:28 by santi      ######      #      ######     */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_name(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc > 0)
		ft_name(argv[0]);
	return (0);
}
