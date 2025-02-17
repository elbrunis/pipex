/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 21:09:30 by biniesta          #+#    #+#             */
/*   Updated: 2024/10/05 21:26:37 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	s_len;
	char	*str;
	size_t	i;
	char	*st;

	st = (char *)s;
	s_len = (size_t)ft_strlen(st);
	str = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (st[i])
	{
		str[i] = st[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
// int	main(void)
// {
// 	const char	*original = "";
// 	char		*duplicada;

// 	duplicada = ft_strdup(original);
// 	if (duplicada != NULL)
// 	{
// 		printf("Cadena duplicada: %s\n", duplicada);
// 	}
// 	else
// 	{
// 		printf("Error al duplicar la cadena.\n");
// 	}
// 	free(duplicada);
// 	return (0);
// }
