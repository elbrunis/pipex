/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:47:37 by biniesta          #+#    #+#             */
/*   Updated: 2024/09/24 14:37:17 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	num;
	int	sing;

	num = 0;
	sing = 1;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n' || *nptr == '\v'
		|| *nptr == '\f' || *nptr == '\r')
	{
		nptr++;
	}
	if ('-' == *nptr || '+' == *nptr)
	{
		if (*nptr == '-')
		{
			sing = -1;
		}
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		num = num * 10 + (*nptr - '0');
		nptr++;
	}
	return (num * sing);
}

/*#include "libft.h"

int	main(void)
{
	char    *str = " -70034fsd";
	int resultado;

	resultado = ft_atoi(str);
	printf("%d\n", resultado);
	return(0);
}*/