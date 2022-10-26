/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   Tg: @elshirak                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 23:26:49 by selbakya          #+#    #+#             */
/*   Updated: 2022/10/09 23:28:27 by selbakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_copy_row(char **board, int permutation, int row)  // function that fills matrix with rows
{
	int	i;

	i = 4;
	while (i > 0)
	{
		board[row][i] = permutation % 10;
		permutation /= 10;
		i --;
	}
}

int	ft_solve_r(char **board, int *perms, int row) // recursively solving board 
{
	int	i;

	i = 0;
	while (i < 24)
	{
		ft_copy_row(board, perms[i], row);
		if (row < 4)
		{
			if (ft_solve_r(board, perms, row + 1))
				return (1);
		}
		else
		{
			if (check_solution(board))
				return (1);
		}
		i++;
	}
	return (0);
}

int	get_permutations(int *perms) // getting non-repeatable strings 
{
	int				i;
	int				num;
	int				count;
	unsigned char	check;

	i = 1234;
	count = 0;
	while (i <= 4321)
	{
		num = i;
		check = 0;
		while (num)
		{
			check ^= 1 << (num % 10);
			num /= 10;
		}
		if (check == 30) // 00011110 = 30
		{
			perms[count] = i;
			count ++;
		}
		i++;
	}
	return (count);
}

int	ft_solve(char **board)
{
	int	perms[24];

	get_permutations(perms);
	return (ft_solve_r(board, perms, 1));
}
