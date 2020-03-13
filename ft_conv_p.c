/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 19:32:56 by tsantoni          #+#    #+#             */
/*   Updated: 2019/12/18 09:40:26 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_itoa_base_llu(uint64_t nb, char *base, int base_len)
{
	char		*res;
	int			i;
	uint64_t	div;
	uint64_t	nb_tmp;

	i = 1;
	div = 1;
	nb_tmp = nb;
	while (nb >= (uint64_t)base_len)
	{
		nb /= base_len;
		div *= base_len;
		i++;
	}
	if (!(res = malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (div > 0)
	{
		res[i++] = base[(nb_tmp / div) % base_len];
		div /= base_len;
	}
	res[i] = '\0';
	return (res);
}

void	ft_display_p(t_data *current, char *ba_h, int nt_gp, int nb_d)
{
	if (current->align == 0)
		ft_display_gap(current, current->width - nt_gp);
	ft_display_zero(current, nt_gp - nb_d);
	ft_puts("0x");
	ft_puts(ba_h);
	current->count += nb_d;
	if (current->align == 1)
		ft_display_gap(current, current->width - nt_gp);
}

int		ft_prepare_p(t_data *current, va_list arg_val, char *base)
{
	int			not_gap;
	uint64_t	buf_arg;
	char		*buf_arg_hex;
	int			nb_digits;

	buf_arg = va_arg(arg_val, uint64_t);
	buf_arg_hex = ft_itoa_base_llu(buf_arg, base, 16);
	nb_digits = ft_strlen(buf_arg_hex) + 2;
	not_gap = nb_digits;
	ft_update_zero(current);
	if (current->prec == 0 && buf_arg == 0)
	{
		ft_display_gap(current, current->width);
		free(buf_arg_hex);
		return (0);
	}
	if (current->prec > nb_digits)
		not_gap = current->prec;
	ft_display_p(current, buf_arg_hex, not_gap, nb_digits);
	free(buf_arg_hex);
	return (0);
}
