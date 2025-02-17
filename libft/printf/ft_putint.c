/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:18:58 by biniesta          #+#    #+#             */
/*   Updated: 2024/12/25 19:13:09 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putint(int num)
{
	char	*str;
	int		i;
	int		count;

	i = 0;
	count = 0;
	str = ft_itoa(num);
	if (!str)
		return (0);
	while (str[i])
	{
		ft_putchar_fd (str[i], 1);
		i++;
		count++;
	}
	free(str);
	return (count);
}
