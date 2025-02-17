/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:25:52 by biniesta          #+#    #+#             */
/*   Updated: 2024/12/25 19:13:24 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putuint(int num)
{
	unsigned int	num1;
	int				count;

	count = 0;
	num1 = (unsigned int)num;
	if (num1 >= 10)
		count = ft_putuint(num1 / 10);
	ft_putnbr_fd(num1 % 10, 1);
	return (count + 1);
}
