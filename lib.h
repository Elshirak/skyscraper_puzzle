/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   Tg: @elshirak                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 20:03:36 by ELSHIRAK          #+#    #+#             */
/*   Updated: 2022/26/10 22:28:36 by ELSHIRAK         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
#define LIB_H

#include <stdlib.h>
#include <unistd.h>

char    **init_array(void);                   // main.c
void    free_array(char **board);
int	ft_check_opposite_inputs(char **board);

int	ft_check_cond(char *str);             //func.c
int	ft_parse(char **board, char *values);
void	print_board(char **board); 

int     ft_solve(char **board);               //ft_solve.c
void	ft_copy_row(char **board, int permutation, int row);
int	ft_solve_r(char **board, int *perms, int row);
int	get_permutations(int *perms); 

int	check_line(char **board, int line);   //check_views.c
int	check_view(char **board, int pos);
int	check_solution(char **board);

int	check_view_top(char **board, int pos); // check_directions.c
int	check_view_bottom(char **board, int pos);
int	check_view_left(char **board, int pos);
int	check_view_right(char **board, int pos);

#endif
