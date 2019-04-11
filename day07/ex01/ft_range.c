/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 19:38:50 by akhossan          #+#    #+#             */
/*   Updated: 2019/02/28 20:00:36 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		*range;
	int		i;

	range = NULL;
	if (min >= max)
		return (NULL);
	range = (int *)malloc((max - min) * sizeof(int));
	if (range)
	{
		i = 0;
		while (min < max)
			range[i++] = min++;
	}
	return (range);
}
