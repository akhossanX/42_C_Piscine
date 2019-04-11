/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 09:51:39 by akhossan          #+#    #+#             */
/*   Updated: 2019/03/04 16:38:57 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	print_hex(int i, unsigned int size, unsigned char *p)
{
	char			*str;
	unsigned int	j;

	j = 0;
	str = "0123456789abcdef";
	while (j < 16 && i + j < size)
	{
		ft_putchar((char)str[(*(p + i + j) / 16) % 16]);
		ft_putchar((char)str[*(p + i + j) % 16]);
		if (j % 2)
			ft_putchar(' ');
		j += 1;
	}
	while (j < 16)
	{
		ft_putchar(' ');
		if (j % 2)
			ft_putchar(' ');
		j += 1;
	}
}

void	addr_to_hex(unsigned int addr)
{
	unsigned int	j;
	unsigned char	mod[9];

	j = 0;
	while (addr / 16 || j < 8)
	{
		mod[7 - j] = addr % 16 + '0';
		addr = addr / 16;
		j++;
	}
	mod[7 - j] = addr % 16 + '0';
	j = 0;
	while (j < 8)
		ft_putchar(mod[j++]);
	ft_putchar(':');
	ft_putchar(' ');
}

void	ft_print_memory(void *addr, unsigned int size)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;
	unsigned char	*p;

	str = "0123456789abcdef";
	p = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		print_hex(i, size, p);
		j = 0;
		while (j < 16 && i + j < size)
		{
			if (*(p + i + j) >= 32 && *(p + i + j) <= 126)
				ft_putchar((char)*(p + i + j));
			else
				ft_putchar('.');
			j += 1;
		}
		ft_putchar('\n');
		i += 16;
	}
}
