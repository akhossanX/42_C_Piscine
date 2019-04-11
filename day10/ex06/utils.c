/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 15:47:18 by akhossan          #+#    #+#             */
/*   Updated: 2019/03/07 23:16:11 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int		is_op(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

int		ft_atoi(char *str)
{
	int		res;
	int		sign;

	while (*str && (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'\
				|| *str == '\f' || *str == '\r'))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * sign);
}

int		do_op(int a, int b, int (*f)(int, int))
{
	int		res;

	res = f(a, b);
	return (res);
}

void	choose_op(char **av, int *res)
{
	if (av[2][0] == '+')
		*res = do_op(ft_atoi(av[1]), ft_atoi(av[3]), &sum);
	else if (av[2][0] == '-')
		*res = do_op(ft_atoi(av[1]), ft_atoi(av[3]), &sub);
	else if (av[2][0] == '*')
		*res = do_op(ft_atoi(av[1]), ft_atoi(av[3]), &mul);
	else if (av[2][0] == '/')
		*res = do_op(ft_atoi(av[1]), ft_atoi(av[3]), &div);
	else if (av[2][0] == '%')
		*res = do_op(ft_atoi(av[1]), ft_atoi(av[3]), &mod);
}
