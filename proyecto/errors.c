/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 12:06:02 by manufern          #+#    #+#             */
/*   Updated: 2023/07/23 19:57:55 by damedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

long	ft_atoi(char *str);

int	errors_argc2(char *argv[])
{
	int	i;

	i = 0;
	if (ft_atoi(argv[1]) > 4294967295)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	while (argv[1][i] != '\0')
	{
		if (!(argv[1][i] <= '9' && argv[1][i] >= '0'))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		i++;
	}
	return (0);
}

int	errors_argc3(char *argv[])
{
	int	i;

	i = 0;
	if (ft_atoi(argv[2]) > 4294967295)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	while (argv[2][i] != '\0')
	{
		if (!(argv[2][i] <= '9' && argv[2][i] >= '0'))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		i++;
	}
	return (0);
}

int	errors(int argc, char *argv[])
{
	if (argc < 2 || argc > 3)
		return (1);
	if (argc == 2)
		return (errors_argc2(argv));
	if (argc == 3)
		return (errors_argc3(argv));
	return (0);
}
