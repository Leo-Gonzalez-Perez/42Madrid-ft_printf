/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux2_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgonzal2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:58:51 by lgonzal2          #+#    #+#             */
/*   Updated: 2022/11/16 15:27:35 by lgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	print_hexa_low(int i, unsigned int n)
{
	char	*bases;
	char	*array_ch;
	int		count;

	bases = "0123456789abcdef";
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

int	pre_print_hexa_low(va_list args)
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
	count = print_hexa_low(i, n);
	return (count);
}

static int	print_u_int(unsigned int r)
{
	static int	rtn;
	char		ascii;

	rtn = 0;
	if (r < 0)
	{
		write (1, "-", 1);
		r *= -1;
		rtn++;
	}
	if (r >= 10)
	{
		print_u_int (r / 10);
		r = r % 10;
		ascii = r + '0';
		write(1, &ascii, 1);
		rtn++;
	}
	else if (r < 10)
	{
		ascii = r + 48;
		write(1, &ascii, 1);
		rtn++;
	}
	return (rtn);
}

int	pre_print_u_int(va_list args)
{
	int			r;
	int			s;

	r = va_arg(args, unsigned int);
	s = print_u_int(r);
	return (s);
}
