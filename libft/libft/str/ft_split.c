/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:56:38 by biniesta          #+#    #+#             */
/*   Updated: 2024/10/13 21:47:17 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_splits(char const *s, char c)
{
	int	i;
	int	result;

	result = 0;
	i = 0;
	if (!s[i])
		return (result);
	if (s[i] != c)
		result++;
	while (s[i])
	{
		if (s[i + 1] && (s[i] == c) && (s[i + 1] != c))
			result++;
		i++;
	}
	return (result);
}

static char	**create_node(char **tab, char const *s, size_t i[3])
{
	size_t	i_free;

	tab[i[2]] = ft_substr(s, i[0], i[1] - i[0] + 1);
	if (!tab[i[2]])
	{
		i_free = 0;
		while (i_free < i[2])
		{
			free(tab[i_free]);
			i_free++;
		}
		free(tab);
		return (NULL);
	}
	return (tab);
}

static char	**create_splits(char **tab, char const *s, char c)
{
	size_t	i[3];

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	if (!s[i[1]])
	{
		tab[i[2]] = NULL;
		return (tab);
	}
	while (s[i[1]])
	{
		if (s[i[1]] == c && s[i[1] + 1] != c)
			i[0] = i[1] + 1;
		if ((s[i[1]] != c) && (s[i[1] + 1] == c || !s[i[1] + 1]))
		{
			tab = create_node(tab, s, i);
			if (!tab)
				return (NULL);
			i[2]++;
		}
		i[1]++;
	}
	tab[i[2]] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = (char **)malloc((count_splits(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result = create_splits(result, s, c);
	return (result);
}
// int	main(void)
// {
// 	char **split = ft_split("Hello world this is Libft", ' ');

// 	for (int i = 0; split[i] != NULL; i++)
// 	{
// 		printf("%s\n", split[i]);
// 		free(split[i]); // Liberar la memoria de cada palabra
// 	}
// 	free(split); // Liberar el array de punteros
// 	return (0);
// }