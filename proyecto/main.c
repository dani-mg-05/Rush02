/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:45:39 by manufern          #+#    #+#             */
/*   Updated: 2023/07/23 20:07:45 by damedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		errors(int argc, char *argv[]);
int		rush(unsigned int nb, char *route);
long	ft_atoi(char *str);

int	main(int argc, char *argv[])
{
	int				digits;
	unsigned int	nb;
	char			*route;

	if (argc == 2)
	{
		route = "numbers.dict";
		nb = ft_atoi(argv[1]);
	}
	if (argc == 3)
	{
		route = argv[1];
		nb = ft_atoi(argv[2]);
	}
	digits = 0;
	if (errors(argc, argv) == 1)
		return (1);
	while (argv[argc - 1][digits] != '\0')
		digits++;
	return (rush(nb, route));
}
