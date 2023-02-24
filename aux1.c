/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux1_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgonzal2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:51:04 by lgonzal2          #+#    #+#             */
/*   Updated: 2023/02/01 17:03:48 by lgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	print_pointer(int i, unsigned long int n)
{
	char	*bases;
	char	*array_ch;
	int		count;

	bases = "0123456789abcdef";
	count = 2;
	array_ch = (char *)malloc(i * sizeof(char));
	i = 0;
	while (n > 0)
	{
		array_ch[i] = bases[n % 16];
		n = n / 16;
		i++;
	}
	i--;
	write (1, "0x", 2);
	while (i >= 0)
	{
		write (1, &array_ch[i], 1);
		count++;
		i--;
	}
	free(array_ch);
	return (count);
}

int	pre_print_pointer(va_list args)
{
	int					i;
	int					count;
	unsigned long int	n;
	unsigned long int	n_cpy;

	n = va_arg(args, unsigned long int);
	n_cpy = n;
	i = 0;
	count = 2;
	if (n == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}
	while (n_cpy > 0)
	{
		n_cpy = n_cpy / 16;
		i++;
	}
	count = print_pointer(i, n);
	return (count);
}

int	print_string(va_list args)
{
	int		i;
	char	*q;

	i = 0;
	q = va_arg(args, char *);
	if (q == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (q[i] != '\0')
	{
		write(1, &q[i], 1);
		i++;
	}
	return (i);
}

static int	print_int(int r)
{
	static int	rtn;
	int			negat;
	char		ascii;

	negat = 0;
	rtn = 0;
	if (r < 0)
	{
		write (1, "-", 1);
		r *= -1;
		negat = 1;
	}
	if (r >= 10)
	{
		print_int (r / 10);
		r = r % 10;
		ascii = r + '0';
		rtn += write(1, &ascii, 1);
	}
	else if (r < 10)
	{
		ascii = r + '0';
		rtn += write(1, &ascii, 1);
	}
	return (rtn + negat);
}

int	pre_print_int(va_list args)
{
	int	r;
	int	s;

	r = va_arg(args, int);
	if (r == -2147483648)
	{
		write(1, "-2147483648", 11);
		s = 11;
		return (s);
	}
	else
		s = print_int(r);
	return (s);
}
