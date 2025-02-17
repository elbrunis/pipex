/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 00:07:33 by biniesta          #+#    #+#             */
/*   Updated: 2024/10/06 14:22:56 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (dstsize > 0)
	{
		i = 0;
		while (i < dstsize - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}
// int	main(void)
// {
// 	char	src[] = "Hello, world!";
// 	char	dst[6];
// 	size_t	copied;

// 	copied = strlcpy(dst, src, sizeof(dst));
// 	printf("Cadena copiada: %s\n", dst);
// 	printf("Tamaño que se intentó copiar: %zu\n", copied);
// 	return (0);
// }
