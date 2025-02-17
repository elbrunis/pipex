/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:59:32 by biniesta          #+#    #+#             */
/*   Updated: 2024/10/05 14:43:37 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
// void to_uppercase(unsigned int index, char *c)
// {
//     (void)index;
//     *c = toupper((unsigned char)*c);
// }
// int main()
// {
//     char str[] = "Drugs";
//     ft_striteri(str ,to_uppercase);
//     printf("%s\n", str);
//     return (0);
// }