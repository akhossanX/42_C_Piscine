/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 12:38:28 by akhossan          #+#    #+#             */
/*   Updated: 2019/03/08 00:22:39 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_opp.h"

void	ft_usage(int a, int b)
{
	unsigned int	len;
	unsigned int	i;

	(void)a;
	(void)b;
	len = sizeof(g_opptab) / sizeof(*g_opptab);
	ft_putstr("error : only [ ");
	i = 0;
	while (i < len)
	{
		ft_putstr(g_opptab[i].op);
		if (g_opptab[i].op[0] != '\0')
			ft_putstr(" ");
		i++;
	}
	ft_putstr("] are accepted.\n");
}

int		main(int ac, char **av)
{
	unsigned long	i;
	unsigned long	len;
	int				num[2];

	if (ac != 4)
		return (0);
	num[0] = ft_atoi(av[1]);
	num[1] = ft_atoi(av[3]);
	len = sizeof(g_opptab) / sizeof(*g_opptab);
	i = 0;
	while (i < len - 1)
	{
		if (ft_strcmp(av[2], g_opptab[i].op) == 0)
		{
			g_opptab[i].f(num[0], num[1]);
			ft_putchar('\n');
			return (0);
		}
		i++;
	}
	g_opptab[i].f(num[0], num[1]);
	return (0);
}
