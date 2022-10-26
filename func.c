/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   Tg: @elshirak                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 20:03:36 by ELSHIRAK          #+#    #+#             */
/*   Updated: 2022/10/09 23:28:36 by ELSHIRAK         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	ft_check_cond(char *str) // the same thing is done by f_parse, however if it works - do not touch 
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 49 && str[i] <= 52) && (str[i + 1] == 32))
			return (0);
		else if (str[i] == 32 && str[i + 1] == 32)
			return (0);
		else if ((str[i] >= 49 && str[i] <= 52)
			&& (str[i + 1] >= 49 && str[i + 1] <= 52))
			return (0);
		i++;
	}
	return (i);
}

int	ft_parse(char **board, char *values) // parsing values, cheking if they are OK with subject
                                             // we can input only [1, 4] numeric
{
	int	i;
	char	c;

	i = 0;
	while (i < 4)
	{
		c = values[i * 2] - 48;
		if (c <= 0 || c > 4)
			return (0);
		board[0][i + 1] = c;
		c = values[i * 2 + 8] - 48;
		if (c <= 0 || c > 4)
			return (0);
		board[5][i + 1] = c;
		c = values[i * 2 + 16] - 48;
		if (c <= 0 || c > 4)
			return (0);
		board[i + 1][0] = c;
		c = values[i * 2 + 24] - 48;
		if (c <= 0 || c > 4)
			return (0);
		board[i + 1][5] = c;
		i++;
	}
	return (1);
}

void	print_board(char **board) // print result matrix
{
	int	i;
	int	j;
	char	c;

	i = 1;
	while (i < 5)
	{
		j = 1;
		while (j < 5)
		{
			c = board[i][j] + 48;
			write(1, &c, 1);
			if (j != 4)
				write(1, " ", 1);
			else
				write(1, "\n", 1);
			j ++;
		}
		i ++;
	}
}
