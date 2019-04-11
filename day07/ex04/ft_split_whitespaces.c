/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 00:46:56 by akhossan          #+#    #+#             */
/*   Updated: 2019/03/05 20:38:42 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*copy_word(char *str);
int		count_words(char *str);
int		is_whitespace(char c);

char	**ft_split_whitespaces(char *str)
{
	char	**array;
	int		i;
	int		k;
	int		words;

	words = count_words(str);
	array = (char **)malloc((words + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	i = 0;
	k = 0;
	while (str[i] && k < words)
	{
		if (!is_whitespace(str[i]))
		{
			array[k] = copy_word(&str[i]);
			k++;
			while (!is_whitespace(str[i]))
				i++;
		}
		else
			i++;
	}
	array[k] = NULL;
	return (array);
}

char	*copy_word(char *str)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && !is_whitespace(str[i]))
		i++;
	if (!(word = malloc((i + 1) * sizeof(char))))
		return (NULL);
	i = -1;
	while (str[++i] && !is_whitespace(str[i]))
		word[i] = str[i];
	word[i] = '\0';
	return (word);
}

int		count_words(char *str)
{
	int		i;
	int		words;

	i = 0;
	while (str[i] && is_whitespace(str[i]))
		i++;
	words = 0;
	while (str[i])
	{
		if (!is_whitespace(str[i]))
		{
			words++;
			while (!is_whitespace(str[i]) && str[i])
				i++;
		}
		else
			i++;
	}
	return (words);
}

int		is_whitespace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}
