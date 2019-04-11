/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 09:21:50 by akhossan          #+#    #+#             */
/*   Updated: 2019/02/27 13:12:38 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_white_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\v' ||\
			c == '\f' || c == '\t' || c == '\r');
}

int		ft_atoi(char *str)
{
	int		i;
	int		sign;
	int		nbr;

	i = 0;
	while (is_white_space(str[i]))
		i++;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	nbr = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i++] - '0';
	}
	return (nbr * sign);
}
