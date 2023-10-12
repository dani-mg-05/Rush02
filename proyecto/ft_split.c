/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:24:05 by damedina          #+#    #+#             */
/*   Updated: 2023/07/22 19:43:47 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	indice;

	indice = 0;
	while (s1[indice] != '\0' && s2[indice] != '\0')
	{
		if (s1[indice] != s2[indice])
			return (s1[indice] - s2[indice]);
		indice++;
	}
	return (s1[indice] - s2[indice]);
}

char	**ft_split_aux(int counter, int longest, char *str, char *charset)
{
	int		i;
	int		j;
	int		k;
	char	**chain;

	chain = (char **)malloc((counter + 1) * sizeof(char *));
	i = 0;
	j = 0;
	while (i < counter)
	{
		chain[i] = (char *)malloc((longest + 1) * sizeof(char));
		k = 0;
		while (str[j] != *charset && str[j] != '\0')
		{
			chain[i][k] = str[j];
			j++;
			k++;
		}
		chain[i][k] = '\0';
		if (ft_strcmp(chain[i], "\0") != 0)
			i++;
		j++;
	}
	return (chain);
}

int	ft_split_aux2(char *str, char *charset, int *size, int *counter)
{
	int	i;
	int	longest;

	i = 1;
	longest = 0;
	while (str[i] != '\0')
	{
		if (str[i] == *charset && str[i - 1] != *charset)
		{
			if (longest < *size)
				longest = *size;
			*size = -1;
			*counter = *counter + 1;
		}
		if (str[i] == *charset && str[i - 1] == *charset)
			*size = -1;
		i++;
		*size = *size + 1;
	}
	if (str[i] == '\0' && str[i - 1] != *charset)
		*counter = *counter + 1;
	return (longest);
}

char	**ft_split(char *str, char *charset)
{
	int		counter;
	int		size;
	int		longest;
	int		i;

	if (ft_strcmp(str, "\0") == 0)
		return (0);
	i = 0;
	while (str[i] == *charset)
	{
		if (str[i + 1] == '\0')
			return (0);
		i++;
	}
	counter = 0;
	size = 1;
	longest = ft_split_aux2(str, charset, &size, &counter);
	if (longest < size)
		longest = size;
	return (ft_split_aux(counter, longest, str, charset));
}
