/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:29:46 by akhossan          #+#    #+#             */
/*   Updated: 2019/02/21 16:20:44 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int		i;
	int		pow;

	pow = 1;
	i = 0;
	if (power >= 0)
	{
		while (++i <= power)
			pow *= nb;
		return (pow);
	}
	return (0);
}
