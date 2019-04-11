/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 21:32:21 by akhossan          #+#    #+#             */
/*   Updated: 2019/03/04 13:33:59 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;

	len = 0;
	while (dest[len] && len < size)
		len++;
	i = 0;
	while ((int)i < (int)(size - len - 1) && src[i])
	{
		dest[i + len] = src[i];
		i++;
	}
	if (i + len < size)
		dest[i + len] = '\0';
	return (len + ft_strlen(src));
}
