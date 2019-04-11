/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 14:35:21 by akhossan          #+#    #+#             */
/*   Updated: 2019/03/06 22:50:25 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		count_words(char *str, char *charset);
int		in(char *charset, char c);
char	*cpy_word(char *str, char *charset);

char	**ft_split(char *str, char *charset)
{
	char	**array;
	int		i;
	int		j;
	int		len;

	len = count_words(str, charset);
	if (!(array = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (str[j] && i < len)
	{
		if (!in(charset, str[j]))
		{
			array[i] = cpy_word(&str[j], charset);
			while (!in(charset, str[j]))
				j++;
			i++;
		}
		else
			j++;
	}
	array[i] = NULL;
	return (array);
}

int		in(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
		if (c == str[i++])
			return (1);
	return (0);
}

int		count_words(char *str, char *charset)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (!in(charset, str[i]))
		{
			words++;
			while (str[i] && !in(charset, str[i]))
				i++;
		}
		else
			i++;
	}
	return (words);
}

char	*cpy_word(char *str, char *charset)
{
	int		i;
	char	*word;

	i = 0;
	while (!in(charset, str[i]))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = -1;
	while (!in(charset, str[++i]))
		word[i] = str[i];
	word[i] = '\0';
	return (word);
}
