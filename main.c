/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   Tg: @elshirak                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:28:29 by selbakya          #+#    #+#             */
/*   Updated: 2022/10/09 23:33:16 by selbakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	ft_check_opposite_inputs(char **board) // due to subject we should handle cases in which sum of string arguments is bigger than 5
                                               // 3 => .... <= 4 is not OK 
                                               // 2 => .... <= 3 is OK
{
	int	i;

	i = 1;
	while (i < 5)
	{
		if (((board[i][0] + board[i][5]) > 5)
			|| ((board[0][i] + board[5][i] > 5)))
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	**init_array(void) // initializing board 6x6 and filling matrix with 0
{
	int		i;
	int		j;
	char	*row;
	char	**board;

	board = malloc(6 * sizeof row);
	i = 0;
	while (i < 6)
	{
		j = 0;
		row = malloc(6);
		while (j < 6)
			row[j++] = 0;
		board[i] = row;
		i ++;
	}
	return (board);
}

void	free_array(char **board) // free memory space at the end
{
	int	i;

	i = 0;
	while (i < 6)
		free(board[i++]);
	free(board);
}

int	main(int argc, char **argv) // parsing argv => input cheking => finding the solution with brut force/error => print result 
{
	char	**board;

	board = init_array();
	if (argc != 2 || (!ft_parse(board, argv[1])))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (ft_check_cond(argv[1]) != 31 || ft_check_opposite_inputs(board))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if ((!ft_solve(board)))
	{
		write(STDOUT_FILENO, "Error\n", 6);
		return (0);
	}
	print_board(board);
	free_array(board);
	return (0);
}
