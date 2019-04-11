/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 18:02:55 by akhossan          #+#    #+#             */
/*   Updated: 2019/03/04 11:55:33 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		is_new_word;

	is_new_word = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (is_new_word)
			{
				str[i] -= 32;
				is_new_word = 0;
			}
		}
		else if (str[i] >= '0' && str[i] <= '9')
			is_new_word = 0;
		else
			is_new_word = 1;
		i++;
	}
	return (str);
}
