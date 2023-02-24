/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux3_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgonzal2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:01:45 by lgonzal2          #+#    #+#             */
/*   Updated: 2022/11/14 14:32:59 by lgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	print_hexa_up(int i, unsigned int n)
{
	char	*bases;
	char	*array_ch;
	int		count;

	bases = "0123456789ABCDEF";
	count = 0;
	array_ch = (char *)malloc(i * sizeof(char));
	i = 0;
	while (n > 0)
	{
		array_ch[i] = bases[n % 16];
		n = n / 16;
		i++;
	}
	i--;
	while (i >= 0)
	{
		write (1, &array_ch[i], 1);
		count++;
		i--;
	}
	free (array_ch);
	return (count);
}

int	pre_print_hexa_up(va_list args)
{
	int				i;
	int				count;
	unsigned int	n;
	unsigned int	n_cpy;

	n = va_arg(args, unsigned int);
	n_cpy = n;
	i = 0;
	count = 2;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (n_cpy > 0)
	{
		n_cpy = n_cpy / 16;
		i++;
	}
	count = print_hexa_up(i, n);
	return (count);
}
