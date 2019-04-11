/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 23:36:05 by akhossan          #+#    #+#             */
/*   Updated: 2019/03/04 17:05:48 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_put_hex(char c)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (c >= 16)
	{
		ft_put_hex(c / 16);
		ft_put_hex(c % 16);
	}
	else
		ft_putchar(hexa[(int)c]);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < 32 && str[i] >= 0) || str[i] == 127)
		{
			ft_putchar('\\');
			if (str[i] < 16)
				ft_putchar('0');
			ft_put_hex(str[i]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
