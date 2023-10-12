/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_numbers2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 16:16:32 by damedina          #+#    #+#             */
/*   Updated: 2023/07/23 16:17:32 by damedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	**ft_split(char *str, char *charset);
long	ft_atoi(char *str);
void	ft_putstr(char *str);
int		write_number(char **dict, int nb);
int		write_ten_aux(char **dict, int nb);
int		write_ten(char **dict, int nb);

int	write_hundred(char **dict, int nb)
{
	if (nb % 100 == 0)
	{
		write_number(dict, nb / 100);
		write(1, " ", 1);
		write_number(dict, 100);
		return (0);
	}
	else
	{
		write_number(dict, nb / 100);
		write(1, " ", 1);
		write_number(dict, 100);
		write(1, " ", 1);
		write_ten(dict, nb % 100);
		return (0);
	}
	return (1);
}

int	write_thousand(char **dict, int nb)
{
	if (nb <= 20000)
		write_number(dict, nb / 1000);
	else if (nb <= 100000)
		write_ten(dict, nb / 1000);
	else
		write_hundred(dict, nb / 1000);
	write (1, " ", 1);
	write_number(dict, 1000);
	if (nb % 1000 != 0)
	{
		write (1, " ", 1);
		if (nb % 1000 >= 100)
			write_hundred(dict, nb % 1000);
		else
			write_ten(dict, nb % 100);
	}
	return (1);
}

int	write_million(char **dict, int nb)
{
	if (nb <= 20000000)
		write_number(dict, nb / 1000000);
	else if (nb <= 100000000)
		write_ten(dict, nb / 1000000);
	else
		write_hundred(dict, nb / 1000000);
	write (1, " ", 1);
	write_number(dict, 1000000);
	if (nb % 1000000 != 0)
	{
		write (1, " ", 1);
		if (nb % 1000000 >= 1000)
			write_thousand(dict, nb % 1000000);
		else if (nb % 1000 >= 100)
			write_hundred(dict, nb % 1000);
		else
			write_ten(dict, nb % 100);
	}
	return (1);
}

int	write_billion(char **dict, unsigned int nb)
{
	write_number(dict, nb / 1000000000);
	write(1, " ", 1);
	write_number(dict, 1000000000);
	if (nb % 1000000000 != 0)
	{
		write (1, " ", 1);
		if (nb % 1000000000 >= 1000000)
			write_million(dict, nb % 1000000000);
		else if (nb % 1000000 >= 1000)
			write_thousand(dict, nb % 1000000);
		else if (nb % 1000 >= 100)
			write_hundred(dict, nb % 1000);
		else
			write_ten(dict, nb % 100);
	}
	return (1);
}
