/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 10:58:09 by akhossan          #+#    #+#             */
/*   Updated: 2019/03/06 21:33:12 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_valid(char *base);
int		ft_atoi_base(char *nbr, char *base, int radix);
int		char_index(char c, char *base);
void	dec_to_base(char *out, int dec, char *base, int *len);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*out;
	int		length[3];
	int		res;
	int		res_tmp;

	length[0] = is_valid(base_from);
	length[1] = is_valid(base_to);
	if (length[0] < 2 || length[1] < 2)
		return (NULL);
	res = ft_atoi_base(nbr, base_from, length[0]);
	res_tmp = res;
	length[2] = 0;
	while (res_tmp != 0 && ++length[2])
		res_tmp /= length[1];
	if (!(out = (char *)malloc(sizeof(char) * (length[2] + 1))))
		return (NULL);
	dec_to_base(out, res, base_to, length);
	return (out);
}

int		is_valid(char *base)
{
	int		i;
	int		j;

	i = -1;
	while (base[++i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i;
		while (base[++j])
			if (base[j] == base[i])
				return (0);
	}
	return (i);
}

int		ft_atoi_base(char *nbr, char *base, int radix)
{
	int		res;
	int		i;
	int		sign;

	res = 0;
	sign = 1;
	while (*nbr == ' ' || *nbr == '\t' || *nbr == '\n')
		nbr++;
	if (*nbr == '+' || *nbr == '-')
	{
		if (*nbr == '-')
			sign = -1;
		nbr++;
	}
	i = -1;
	while (nbr[++i])
	{
		if (char_index(nbr[i], base) == -1)
			break ;
		res = res * radix + char_index(nbr[i], base);
	}
	return (res * sign);
}

int		char_index(char c, char *base)
{
	int		i;

	i = -1;
	while (base[++i])
		if (c == base[i])
			return (i);
	return (-1);
}

void	dec_to_base(char *out, int dec, char *base, int *len)
{
	out[len[2]] = '\0';
	if (dec == 0)
		out[0] = base[0];
	else if (dec < 0 && ++len[2] && (dec *= -1))
		out[0] = '-';
	while (dec)
	{
		out[--len[2]] = base[dec % len[1]];
		dec /= len[1];
	}
}
