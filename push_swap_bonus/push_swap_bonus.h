/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <ereginia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:11:43 by ereginia          #+#    #+#             */
/*   Updated: 2022/02/06 14:43:28 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include "libft.h"

typedef struct s_stack
{
	int				value;
	int				side;
	struct s_stack	*next;
}	t_stack;

# define BUFFER_SIZE 42

//push_swap_bonus.c
char	*string_output(char *operation);
//get_next_line.c
char	*get_next_line(int fd);
//ft_validation.c
void	ft_validate(int count, char **vals);
void	stack_a_init(t_stack **stack, int count, char **val);
void	ft_check_same_numbers(t_stack **stack, int size);
//ft_stk_base_op.c
t_stack	*ft_stknew(int value);
int		ft_stksize(t_stack *stack);
t_stack	*ft_stklast(t_stack *lst);
t_stack	*ft_stkprelast(t_stack *lst);
void	ft_stkadd_back(t_stack **lst, t_stack *new);
//ft_clean.c
void	ft_free_split(char **args);
void	ft_free_stack(t_stack **stacks, int i);
//stack_operate
void	ft_swap(t_stack **st_ptr, t_stack *stack);
void	ft_rotate(t_stack **st_ptr, t_stack *stack);
void	ft_reverse_rotate(t_stack **st_ptr, t_stack *stack);
void	ft_push(t_stack **st_ptr_a, t_stack **st_ptr_b,
			t_stack *stack_a, t_stack *stack_b);
void	ft_merge(t_stack **st_ptr_a, t_stack **st_ptr_b,
			t_stack *stack_a, t_stack *stack_b);
//ft_sort_checker.c
int		ft_is_sorted_left(t_stack *stack);
//ft_command_handler.c
void	ft_command_handler(t_stack	**stack, char *str);

#endif
