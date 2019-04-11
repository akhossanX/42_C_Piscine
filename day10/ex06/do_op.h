/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 15:43:21 by akhossan          #+#    #+#             */
/*   Updated: 2019/03/07 23:30:16 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H
# define DIV_BY_ZERO	"Stop : division by zero\n"
# define MOD_BY_ZERO	"Stop : modulo by zero\n"
# include <unistd.h>

int		is_op(char c);
int		sum(int a, int b);
int		sub(int a, int b);
int		mul(int a, int b);
int		div(int a, int b);
int		mod(int a, int b);
int		ft_atoi(char *str);
void	ft_putnbr(int nbr);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	choose_op(char **av, int *res);
int		do_op(int a, int b, int (*f)(int, int));

#endif
