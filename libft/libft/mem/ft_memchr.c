/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:23:48 by biniesta          #+#    #+#             */
/*   Updated: 2024/10/05 13:57:01 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	unsigned char		ltr;
	size_t				i;

	str = (const unsigned char *)s;
	ltr = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == ltr)
		{
			return ((void *)(str + i));
		}
		i++;
	}
	return (NULL);
}
// int	main(void)
// {
// 	char	str[] = "Hola mundo";
// 	char		ltr;
// 	void *resultado;

// 	ltr = 'n';
// 	resultado = ft_memchr(str, ltr, 20);
// 	if(resultado)
// 	{
// 	printf("%ld\n", (char *)resultado - str);
// 	}
// 	else
// 	{
// 		printf("NULL\n");
// 	}
// 	return (0);
// }
