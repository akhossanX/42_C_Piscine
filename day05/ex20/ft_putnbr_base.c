/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 09:42:03 by akhossan          #+#    #+#             */
/*   Updated: 2019/03/04 15:31:42 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void			ft_putchar(char c);

int				is_sign(char c)
{
	return (c == '+' || c == '-');
}

unsigned int	is_valid(char *base)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (!(base[i] >= 32 && base[i] < 127) || is_sign(base[i]))
			return (0);
		j = i + 1;
		while (base[j] != '\0')
			if (base[i] == base[j++])
				return (0);
		i++;
	}
	return (i);
}

void			convert(char *base, unsigned int radix, unsigned int nb)
{
	if (nb / radix == 0)
	{
		ft_putchar(base[nb % radix]);
		return ;
	}
	convert(base, radix, nb / radix);
	ft_putchar(base[nb % radix]);
}

void			ft_putnbr_base(int nbr, char *base)
{
	unsigned int	radix;

	radix = is_valid(base);
	if (radix > 1)
	{
		if (nbr < 0)
		{
			if (nbr == -2147483648)
			{
				ft_putchar('-');
				convert(base, radix, 2147483648);
				return ;
			}
			ft_putchar('-');
			nbr *= -1;
		}
		convert(base, radix, nbr);
	}
}
