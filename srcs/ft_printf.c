/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 10:11:29 by tsantoni          #+#    #+#             */
/*   Updated: 2019/12/19 17:40:51 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int		ft_display(t_data *current, va_list arg_val)
{
	if (current->conv == 's')
		ft_display_s(current, arg_val);
	if (current->conv == 'c')
		ft_display_c(current, arg_val);
	if (current->conv == 'u')
		ft_display_u(current, arg_val);
	if (current->conv == 'd')
		ft_prepare_d(current, arg_val);
	if (current->conv == 'i')
		ft_prepare_d(current, arg_val);
	if (current->conv == 'x')
		ft_prepare_x(current, arg_val, "0123456789abcdef");
	if (current->conv == 'X')
		ft_prepare_x(current, arg_val, "0123456789ABCDEF");
	if (current->conv == 'p')
		ft_prepare_p(current, arg_val, "0123456789abcdef");
	if (current->conv == '%')
		ft_display_pc(current);
	return (-1);
}

int		ft_printf(const char *fmt, ...)
{
	va_list	arg_val;
	t_data	*current;

	if (!(current = (t_data*)malloc(sizeof(t_data))))
		return (-1);
	va_start(arg_val, fmt);
	ft_init_data(current);
	while (fmt[current->fmt_i])
	{
		if (ft_is_token('%', fmt[current->fmt_i]) == 0)
			ft_putchar_count(current, fmt[current->fmt_i]);
		else
		{
			ft_reinit_data(current);
			ft_fill_data(current, fmt, arg_val);
			ft_display(current, arg_val);
			current->fmt_i = current->conv_i;
		}
		current->fmt_i++;
	}
	free(current);
	va_end(arg_val);
	return (current->count);
}
