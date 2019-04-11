/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:48:12 by akhossan          #+#    #+#             */
/*   Updated: 2019/03/06 19:27:57 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int		main(int ac, char **av)
{
	int		res;

	if (ac != 4)
		return (0);
	if (!is_op(av[2][0]))
	{
		ft_putstr("0\n");
		return (0);
	}
	if (ft_atoi(av[3]) == 0 && av[2][0] == '/')
	{
		ft_putstr(DIV_BY_ZERO);
		return (0);
	}
	if (ft_atoi(av[3]) == 0 && av[2][0] == '%')
	{
		ft_putstr(MOD_BY_ZERO);
		return (0);
	}
	choose_op(av, &res);
	ft_putnbr(res);
	ft_putchar('\n');
	return (0);
}
