/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:44:53 by biniesta          #+#    #+#             */
/*   Updated: 2024/10/05 14:49:06 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen((char *)s);
	str = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// #include <ctype.h>
// char to_uppercase(unsigned int index, char c)
// {
//     (void)index;
//     return (toupper(c));
// }
// int main()
// {
//     char *result;
//     result = ft_strmapi("hola, buenassfghsfgh",to_uppercase);
//     printf("%s\n", result);
//     free(result);
//     return (0);
// }