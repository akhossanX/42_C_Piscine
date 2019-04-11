/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 22:17:32 by akhossan          #+#    #+#             */
/*   Updated: 2019/03/06 21:18:20 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		param_size(int argc, char **argv)
{
	int		size;
	int		i;
	int		j;

	size = 0;
	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
			size++;
		size++;
	}
	return (size);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		i;
	int		j;
	int		size;
	char	*params;

	size = param_size(argc, argv);
	params = (char *)malloc((size) * sizeof(char));
	i = 0;
	while (i < size)
		params[i++] = '\0';
	size = 0;
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
			params[size++] = argv[i][j++];
		i++;
		if (i < argc)
			params[size++] = '\n';
	}
	params[size] = '\0';
	return (params);
}
