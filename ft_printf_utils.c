/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfctns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:04:46 by tsantoni          #+#    #+#             */
/*   Updated: 2019/12/17 22:14:59 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_is_token(char token, char tocheck)
{
	if (tocheck == token)
		return (1);
	return (0);
}

void	ft_parse_gap(t_data *current)
{
	if (current->align == 1)
		current->gap = ' ';
	else
	{
		if (current->zero == 0)
			current->gap = ' ';
		else
			current->gap = '0';
	}
}

void	ft_display_gap(t_data *current, int tofill)
{
	int	i;

	i = 0;
	if (tofill > 0)
	{
		while (i < tofill)
		{
			ft_putchar(current->gap);
			current->count += 1;
			i++;
		}
	}
}

void	ft_display_zero(t_data *current, int tofill)
{
	int	i;

	i = 0;
	if (tofill > 0)
	{
		while (i < tofill)
		{
			ft_putchar('0');
			current->count += 1;
			i++;
		}
	}
}
