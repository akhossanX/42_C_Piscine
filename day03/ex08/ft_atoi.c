/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 11:13:24 by akhossan          #+#    #+#             */
/*   Updated: 2019/02/20 19:25:24 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_sign(char c)
{
	return ((c == '+' || c == '-') ? 1 : 0);
}

int		is_space(char c)
{
	return ((c == ' ' || (c <= 13 && c >= 9)) ? 1 : 0);
}

int		is_digit(char c)
{
	return ((c <= 57 && c >= 48) ? 1 : 0);
}

int		ft_atoi(char *str)
{
	int	decimal;
	int	sign;

	sign = 1;
	decimal = 0;
	while (*str && !is_digit(*str))
	{
		if (is_sign(*str) && is_digit(*(str + 1)))
		{
			if (*str == '-')
				sign = -1;
			str++;
			break ;
		}
		else if (is_space(*str) && (is_space(*(str + 1)) || is_sign(*(str + 1))\
							|| is_digit(*(str + 1))))
			str++;
		else
			return (0);
	}
	while (*(str) && is_digit(*str))
		decimal = decimal * 10 + (*(str++) - '0');
	return (sign * decimal);
}
