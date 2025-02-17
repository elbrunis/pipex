/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 11:10:57 by biniesta          #+#    #+#             */
/*   Updated: 2024/10/07 00:02:07 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	while (i >= 0)
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i--;
	}
	return (NULL);
}
// int	main(void)
// {
// 	char  str[] = "Hola buenas";
// 	char lttr = 'j';
// 	char    *resultado;

// 	resultado = ft_strrchr(str, lttr);
// 	if(resultado)
// 	{
// 		printf("El caraacter'%c'fue encontrado en la posicion: %ld\n", lttr,
// 			resultado - str);
// 	}
// 	else
// 	{
// 		printf("El caracter '%c'no fue encontrado\n", lttr);
// 	}
// 	return(0);
// }