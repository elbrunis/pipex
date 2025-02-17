/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:28:08 by biniesta          #+#    #+#             */
/*   Updated: 2024/10/05 18:41:09 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*find_str(const char *haystack, const char *needle, size_t len,
		size_t needle_len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i <= (len - needle_len))
	{
		j = 0;
		while (j < needle_len && haystack[i + j] == needle[j])
		{
			j++;
		}
		if (j == needle_len)
		{
			return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	haystack_len;
	size_t	needle_len;

	if (needle[0] == '\0')
		return ((char *)haystack);
	haystack_len = (size_t)ft_strlen((char *)haystack);
	needle_len = (size_t)ft_strlen((char *)needle);
	if (len > haystack_len)
		len = haystack_len;
	if (needle_len > len)
		return (NULL);
	return (find_str(haystack, needle, len, needle_len));
}
// int	main(void)
// {
// 	const char *haystack = "mundo";
// 	const char *needle = "n";
// 	char *resultado;

// 	resultado = ft_strnstr(haystack, needle, 20);
// 	if (resultado)
// 	{
// 		printf("%s\n", resultado);
// 	}
// 	else
// 	{
// 		printf("NULL\n");
// 	}
// 	return (0);
// }