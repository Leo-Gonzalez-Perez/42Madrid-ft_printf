/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgonzal2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:35:53 by lgonzal2          #+#    #+#             */
/*   Updated: 2023/01/14 12:33:52 by lgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	print_char(va_list args)
{
	int		rtn;
	char	y;

	rtn = 0;
	y = va_arg(args, int);
	write(1, &y, 1);
	rtn++;
	return (rtn);
}

int	*view_var(va_list args, const char *par, int *prtn)
{
	int	h;

	h = 0;
	if ((*par) == '%')
	{
		write(1, "%", 1);
		(*prtn)++;
	}
	else if (((*par) == 'd') || ((*par) == 'i'))
		(*prtn) += pre_print_int(args);
	else if ((*par) == 'c')
		(*prtn) += print_char(args);
	else if ((*par) == 's')
		(*prtn) += print_string(args);
	else if ((*par) == 'p')
		(*prtn) += pre_print_pointer(args);
	else if ((*par) == 'u')
		(*prtn) += pre_print_u_int(args);
	else if ((*par) == 'x')
		(*prtn) += pre_print_hexa_low(args);
	else if ((*par) == 'X')
		(*prtn) += pre_print_hexa_up(args);
	return (prtn);
}

static int	print_null(int *prtn)
{
	*prtn = 6;
	write (1, "(null)", 6);
	return (*prtn);
}

static void	print_no_per(char str, int *prtn, int *i)
{
	write(1, &str, 1);
	(*prtn)++;
	(*i)++;
}

int	ft_printf(const char *str, ...)
{
	int		rtn;
	int		*prtn;
	int		i;
	va_list	args;

	i = 0;
	rtn = 0;
	prtn = &rtn;
	va_start(args, str);
	if (!str)
		return (print_null(prtn));
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			print_no_per(str[i], prtn, &i);
		else
		{
			view_var(args, &(str[i + 1]), prtn);
			i += 2;
		}
	}
	va_end (args);
	return (rtn);
}
/*
#include <stdio.h>
int	main(void)
{
	int	o_cnt;
//	int	c_cnt;
	int	test;

	test = 55221236980;
	o_cnt = printf("\nO:%d\n", test);
//	c_cnt = ft_printf("\nC:%d\n", test);
	o_cnt = printf("\001\002\007\v\010\f\r\n");
//	c_cnt = ft_printf("\001\002\007\v\010\f\r\n");
//	printf("\nO:%d\nC:%d\n", o_cnt, c_cnt);
	return (0);
}*/
