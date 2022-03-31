/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <ereginia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:42:07 by ereginia          #+#    #+#             */
/*   Updated: 2022/02/06 14:35:15 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# include "libft.h"

typedef struct s_stack
{
	int				value;
	int				side;
	struct s_stack	*next;
}	t_stack;
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
//ft_stk_descript.c
int		find_stk_median(t_stack *stack);
t_stack	*find_stk_min(t_stack *stack);
t_stack	*find_stk_max(t_stack *stack);
//ft_is_sorted.c
int		ft_max_order(t_stack **stack);
int		ft_max_order_side(t_stack **stack, int side);
int		ft_premax_order_side(t_stack **stack, int side);
int		ft_unic_side(t_stack **stack, int side);
//ft_clean.c
void	ft_free_split(char **args);
void	ft_free_stack(t_stack **stacks, int i);
//ft_quick_sort_left.c
void	chanking_left(t_stack **stack, int order);
int		ft_is_sorted_left(t_stack *stack);
void	three_handle_left(t_stack **stack);
//ft_quick_sort_l_utils.c
void	ft_unic_three_handle_left(t_stack **stack);
void	ft_not_unic_three_handle_left(t_stack **stack, int iter);
void	ft_normal_chank_handler_left(t_stack **stack, int k, int order);
//ft_quick_sort_right.c
void	chanking_right(t_stack **stack, int order);
int		ft_is_sorted_right(t_stack *stack);
void	three_handle_right(t_stack **stack);
//ft_quick_sort_r_utils.c
void	ft_unic_three_handle_right(t_stack **stack);
void	ft_not_unic_three_handle_right(t_stack **stack, int iter);
void	ft_normal_chank_handler_right(t_stack **stack, int k, int order);
//stack_operate
void	ft_swap(t_stack **st_ptr, t_stack *stack);
void	ft_rotate(t_stack **st_ptr, t_stack *stack);
void	ft_reverse_rotate(t_stack **st_ptr, t_stack *stack);
void	ft_push(t_stack **st_ptr_a, t_stack **st_ptr_b,
			t_stack *stack_a, t_stack *stack_b);
void	ft_merge(t_stack **st_ptr_a, t_stack **st_ptr_b,
			t_stack *stack_a, t_stack *stack_b);
//ft_print_optimaise.c
char	*string_output(char *operation);
int		string_optimase_rotate(char *str);
void	ft_free_str(char **strs);
void	optimase(char *stam);
//ft_print_opt_cases.c
int		string_optimase_rotate(char *str);
int		string_optimase_push(char *str);
int		string_optimase_swap(char *str);

#endif
