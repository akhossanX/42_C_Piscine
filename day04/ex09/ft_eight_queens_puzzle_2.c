/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:48:38 by akhossan          #+#    #+#             */
/*   Updated: 2019/02/20 18:42:41 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define N	8

void	ft_putchar(char c);

void	disp_combination(int board[][N])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < N && j < N)
	{
		if (board[i][j] != 1)
			i++;
		else
		{
			ft_putchar(i + 1 + '0');
			i = 0;
			j++;
		}
	}
	ft_putchar('\n');
}

int		ft_abs(int nb)
{
	return (nb < 0 ? -nb : nb);
}

int		is_safe(int board[][N], int row, int col)
{
	int	i;
	int j;

	i = -1;
	while (++i < N)
	{
		j = -1;
		while (++j < col)
			if ((i == row || ft_abs(i - row) == ft_abs(j - col))\
				&& board[i][j])
				return (0);
	}
	return (1);
}

void	solve(int board[][N], int col)
{
	int	row;

	if (col == N)
	{
		disp_combination(board);
		return ;
	}
	row = 0;
	while (row < N)
	{
		if (is_safe(board, row, col))
		{
			board[row][col] = 1;
			solve(board, col + 1);
			board[row][col] = 0;
		}
		row++;
	}
}

void	ft_eight_queens_puzzle_2(void)
{
	int		board[N][N];
	int		i;
	int		j;

	i = -1;
	while (++i < N)
	{
		j = -1;
		while (++j < N)
			board[i][j] = 0;
	}
	solve(board, 0);
}
