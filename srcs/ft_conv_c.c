/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 12:50:57 by tsantoni          #+#    #+#             */
/*   Updated: 2019/12/15 12:51:10 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_display_c(t_data *current, va_list arg_val)
{
	char	buf_arg;
	int		tofill;

	current->prec = -1;
	buf_arg = va_arg(arg_val, int);
	tofill = current->width - 1;
	if (current->align == 0)
		ft_display_gap(current, tofill);
	ft_putchar(buf_arg);
	current->count += 1;
	if (current->align == 1)
		ft_display_gap(current, tofill);
}
