/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 09:29:11 by tsantoni          #+#    #+#             */
/*   Updated: 2019/12/27 09:58:35 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putchar_count(t_data *current, char c)
{
	write(1, &c, 1);
	current->count += 1;
}

void	ft_putnbr(int nb)
{
	int div;

	div = 1;
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	while ((nb / div) >= 10)
		div *= 10;
	while (div > 0)
	{
		ft_putchar((nb / div) % 10 + '0');
		div /= 10;
	}
}

void	ft_putnbr_l(long nb)
{
	int div;

	div = 1;
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	while ((nb / div) >= 10)
		div *= 10;
	while (div > 0)
	{
		ft_putchar((nb / div) % 10 + '0');
		div /= 10;
	}
}

void	ft_putnbr_u(unsigned int nb)
{
	int div;

	div = 1;
	while ((nb / div) >= 10)
		div *= 10;
	while (div > 0)
	{
		ft_putchar((nb / div) % 10 + '0');
		div /= 10;
	}
}
