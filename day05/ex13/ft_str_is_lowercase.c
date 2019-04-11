/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 18:52:19 by akhossan          #+#    #+#             */
/*   Updated: 2019/02/27 14:31:19 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_lowercase(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		if (!(str[i] >= 'a' && str[i++] <= 'z'))
			return (0);
	return (1);
}
