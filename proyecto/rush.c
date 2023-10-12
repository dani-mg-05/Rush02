/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 18:58:28 by manufern          #+#    #+#             */
/*   Updated: 2023/07/23 19:05:38 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	**ft_split(char *str, char *charset);
long	ft_atoi(char *str);
void	ft_putstr(char *str);
int		write_number(char **dict, int nb);
int		write_ten_aux(char **dict, int nb);
int		write_ten(char **dict, int nb);
int		write_hundred(char **dict, int nb);
int		write_thousand(char **dict, int nb);
int		write_million(char **dict, int nb);
int		write_billion(char **dict, unsigned int nb);

int	write_dict(char **dict, unsigned int nb)
{
	if (nb <= 20)
		write_number(dict, nb);
	else if (nb < 100)
		write_ten(dict, nb);
	else if (nb < 1000)
		write_hundred(dict, nb);
	else if (nb < 1000000)
		write_thousand(dict, nb);
	else if (nb < 1000000000)
		write_million(dict, nb);
	else
		write_billion(dict, nb);
	write(1, "\n", 1);
	return (0);
}

int	rush(unsigned int nb, char *route)
{
	char	str[2000000];
	char	**dict;
	int		i;
	int		fd;

	fd = open(route, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Dict Error\n", 11);
		return (1);
	}
	read(fd, str, 1999999);
	close(fd);
	dict = ft_split(str, "\n");
	if (write_dict(dict, nb) == 1)
	{
		write(2, "Dict Error\n", 11);
		return (1);
	}
	i = 0;
	while (dict[i])
		free(dict[i++]);
	free(dict);
	return (0);
}
