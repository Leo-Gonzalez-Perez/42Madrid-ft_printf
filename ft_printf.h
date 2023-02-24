/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgonzal2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:51:24 by lgonzal2          #+#    #+#             */
/*   Updated: 2022/11/14 14:35:39 by lgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		pre_print_pointer(va_list args);
int		print_string(va_list args);
int		*view_var(va_list args, const char *par, int *prtn);
int		ft_printf(const char *str, ...);
int		pre_print_int(va_list args);
int		pre_print_hexa_low(va_list args);
int		pre_print_u_int(va_list args);
int		pre_print_hexa_up(va_list args);

#endif
