/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:00:15 by lmoulin           #+#    #+#             */
/*   Updated: 2019/10/16 15:33:42 by lmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int			get_size(unsigned int n)
{
	unsigned int	size;

	size = 0;
	while (n >= 10)
	{
		n /= 10;
		++size;
	}
	return (size + 1);
}

char				*ft_uitoa(unsigned int n)
{
	char			*res;
	int				size;
	int				index;
	unsigned int	nb;

	nb = (unsigned int)n;
	size = get_size(nb);
	index = 0;
	if (!(res = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	index = size - 1;
	while (nb >= 10)
	{
		res[index--] = (char)(nb % 10 + 48);
		nb /= 10;
	}
	res[index] = (char)(nb % 10 + 48);
	res[size] = '\0';
	return (res);
}
