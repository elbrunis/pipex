/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:39:54 by biniesta          #+#    #+#             */
/*   Updated: 2024/10/05 13:39:52 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	int_lenght(int num)
{
	size_t	lenght;

	lenght = 0;
	if (num <= 0)
		lenght++;
	while (num != 0)
	{
		num /= 10;
		lenght++;
	}
	return (lenght);
}

static char	*num_to_char(int n, size_t nl, char *str)
{
	unsigned int	num;

	if (n < 0)
		num = -n;
	else
		num = n;
	while (num != 0)
	{
		str[--nl] = ((num % 10) + '0');
		num = num / 10;
	}
	if (n < 0)
		str[--nl] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	size_t	nl;
	char	*str;

	nl = int_lenght(n);
	str = (char *)malloc(sizeof(char) * (nl + 1));
	if (!str)
		return (NULL);
	str[nl] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	num_to_char(n, nl, str);
	return (str);
}
// int	main(void)
// {
// 	char *result = ft_itoa(98776);
// 	printf("%s\n", result);
// 	free(result);
// 	return (0);
// }