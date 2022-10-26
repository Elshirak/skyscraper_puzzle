/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_directions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   Tg: @elshirak                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 23:26:04 by selbakya          #+#    #+#             */
/*   Updated: 2022/10/09 23:28:06 by selbakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	check_view_top(char **board, int pos)
{
	char	count;
	int		i;
	char	max;
	char	cur_val;

	i = 1;
	max = 0;
	count = 0;
	while (i < 5)
	{
		cur_val = board[i][pos % 4 + 1];
		if (cur_val > max)
		{
			max = cur_val;
			count++;
		}
		i++;
	}
	if (count != board[0][pos % 4 + 1])
		return (0);
	return (1);
}

int	check_view_bottom(char **board, int pos)
{
	char	count;
	int		i;
	char	max;
	char	cur_val;

	i = 4;
	max = 0;
	count = 0;
	while (i >= 1)
	{
		cur_val = board[i][pos % 4 + 1];
		if (cur_val > max)
		{
			max = cur_val;
			count++;
		}
		i--;
	}
	if (count != board[5][pos % 4 + 1])
		return (0);
	return (1);
}

int	check_view_left(char **board, int pos)
{
	char	count;
	int		i;
	char	max;
	char	cur_val;

	i = 1;
	max = 0;
	count = 0;
	while (i < 5)
	{
		cur_val = board[pos % 4 + 1][i];
		if (cur_val > max)
		{
			max = cur_val;
			count++;
		}
		i++;
	}
	if (count != board[pos % 4 + 1][0])
		return (0);
	return (1);
}

int	check_view_right(char **board, int pos)
{
	char	count;
	int		i;
	char	max;
	char	cur_val;

	i = 4;
	max = 0;
	count = 0;
	while (i >= 1)
	{
		cur_val = board[pos % 4 + 1][i];
		if (cur_val > max)
		{
			max = cur_val;
			count++;
		}
		i--;
	}
	if (count != board[pos % 4 + 1][5])
		return (0);
	return (1);
}
