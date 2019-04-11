/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 23:12:35 by akhossan          #+#    #+#             */
/*   Updated: 2019/02/20 19:06:03 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define N	8

void	ft_putchar(char c);

int		ft_abs(int nb)
{
	return (nb < 0 ? -nb : nb);
}

void	init(int board[][N])
{
	int	i;
	int	j;

	i = -1;
	while (++i < N)
	{
		j = -1;
		while (++j < N)
			board[i][j] = 0;
	}
}

int		is_safe(int board[][N], int row, int col)
{
	int	i;
	int	j;

	i = -1;
	while (++i < N)
	{
		j = -1;
		while (++j < col)
			if ((i == row || ft_abs(j - col) == ft_abs(i - row))\
					&& board[i][j])
				return (0);
	}
	return (1);
}

void	solve(int board[][N], int col, int *combinations)
{
	int		row;

	if (col >= N)
	{
		*combinations = *combinations + 1;
		return ;
	}
	row = 0;
	while (row < N)
	{
		if (is_safe(board, row, col))
		{
			board[row][col] = 1;
			solve(board, col + 1, combinations);
			board[row][col] = 0;
		}
		row++;
	}
}

int		ft_eight_queens_puzzle(void)
{
	int		board[N][N];
	int		combinations;

	combinations = 0;
	init(board);
	solve(board, 0, &combinations);
	return (combinations);
}
