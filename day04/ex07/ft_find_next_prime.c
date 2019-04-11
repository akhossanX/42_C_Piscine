/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 22:31:19 by akhossan          #+#    #+#             */
/*   Updated: 2019/02/27 19:26:53 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	int		i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (i <= (nb / 2))
	{
		if ((nb % i) != 0)
			i++;
		else
			return (0);
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	if (nb <= 0)
		return (2);
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}
