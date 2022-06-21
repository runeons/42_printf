/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 19:18:37 by tsantoni          #+#    #+#             */
/*   Updated: 2019/12/18 09:40:41 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_display_s(t_data *current, va_list arg_val)
{
	char	*buf_arg;
	char	*toprint;
	int		tofill;
	int		len;

	buf_arg = va_arg(arg_val, char *);
	toprint = NULL;
	if (current->prec >= 0 && buf_arg)
		toprint = ft_strndup(buf_arg, current->prec);
	else if (current->prec >= 0 && buf_arg == NULL)
		toprint = ft_strndup(("(null)"), current->prec);
	else if (current->prec == -1 && buf_arg)
		toprint = ft_strdup(buf_arg);
	else if (current->prec == -1 && buf_arg == NULL)
		toprint = ft_strdup("(null)");
	len = ft_strlen(toprint);
	tofill = current->width - len;
	if (current->align == 0)
		ft_display_gap(current, tofill);
	ft_puts(toprint);
	current->count += len;
	if (current->align == 1)
		ft_display_gap(current, tofill);
	if (toprint)
		free(toprint);
}
