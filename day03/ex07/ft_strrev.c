/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 10:05:39 by akhossan          #+#    #+#             */
/*   Updated: 2019/02/16 11:13:02 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	int		length;
	int		j;
	char	temp;

	length = 0;
	while (str[length])
		length++;
	j = 0;
	while (j < length / 2)
	{
		temp = str[j];
		str[j] = str[length - 1 - j];
		str[length - 1 - j] = temp;
		j++;
	}
	return (str);
}
