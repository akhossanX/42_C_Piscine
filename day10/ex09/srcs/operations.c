/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:29:42 by akhossan          #+#    #+#             */
/*   Updated: 2019/03/07 20:07:54 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>

void		ft_add(int a, int b)
{
	ft_putnbr(a + b);
}

void		ft_sub(int a, int b)
{
	ft_putnbr(a - b);
}

void		ft_mul(int a, int b)
{
	ft_putnbr(a * b);
}

void		ft_div(int a, int b)
{
	if (b == 0)
	{
		ft_putstr("Stop : division by zero");
		return ;
	}
	ft_putnbr(a / b);
}

void		ft_mod(int a, int b)
{
	if (b == 0)
	{
		ft_putstr("Stop : modulo by zero");
		return ;
	}
	ft_putnbr(a % b);
}
