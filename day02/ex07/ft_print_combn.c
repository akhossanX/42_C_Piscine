
#include <unistd.h>
#include <stdlib.h>

void	ft_print(int *arr,int index, int prev, int size);
void	ft_disp(int *arr, int size);
int		last_comb(int *arr, int size);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		last_comb(int *arr, int size)
{
	int		last;

	last = 9;
	while (--size >= 0)
		if (arr[size] != last--)
			return (0);
	return (1);
}

void	ft_print_combn(int n)
{
	int		arr[n];

	//arr = (int *)malloc(sizeof(int) * n);
	//if (!arr)
	//	return ;
	if (!(n > 0 && n < 10))
		return ;
	ft_print(arr, 0, -1, n);	
	//free(arr);
}

void	ft_print(int *arr,int index, int prev, int size)
{
	int		i;

	if (index == size)
	{
		ft_disp(arr, size);
		if (!last_comb(arr, size))
		{
				ft_putchar(',');
				ft_putchar(' ');
		}
		return ;
	}
	i = 0;
	while (i < 10)
	{
		if (i > prev)
		{
				arr[index] = i;
				ft_print(arr, index + 1, arr[index], size);
				//arr[index] = -1;
		}
		i++;
	}
}

void	ft_disp(int *arr, int size)
{
	int		i;

	i = 0;
	while (i < size)
		ft_putchar(arr[i++] + '0');
}

int		main(int ac, char **av)
{
	(void)ac;
	ft_print_combn(atoi(av[1]));
}
