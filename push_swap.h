/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:05:12 by melshafi          #+#    #+#             */
/*   Updated: 2023/12/18 09:05:12 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

/*
Stack Nodes:
	(target) points to another node that will have the cheapest cost
	(target_cost) cost of the cheapest move
	(above_below) determines if the index is below or above the median length
	of the stack and target nodes stack
 */
typedef struct s_stack_node
{
	int					value;
	int					index;
	int					target_cost;
	int					above_below;
	struct s_stack_node	*target;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}	t_stack_node;

/********************************************************
	Stack Initialization and Manipulation functions
********************************************************/
//Initializes the stacks, filling stack A with list of integers
t_stack_node	*stack_init(char **values);
//Returns the size of a stack(number of nodes within the stack)
int				stack_size(t_stack_node *lst);
//Returns the top element within a stack
t_stack_node	*stack_last(t_stack_node *lst);
//Returns the bottom element within a stack
t_stack_node	*stack_first(t_stack_node *lst);
//Deletes given node from a stack
//(Default del function should be free)
void			stack_delone(t_stack_node *lst);
//Clears and deletes all nodes of a stack
void			stack_clear(t_stack_node *lst);
//Creates a new node
//(Uses Malloc with NULL Protection)
t_stack_node	*stack_new_node(int value, t_stack_node *next);
//Adds new node under the given node
void			stack_append(t_stack_node *lst, t_stack_node *obj);
//Adds new node to the top of a stack
void			stack_add_top(t_stack_node **lst, t_stack_node *obj);
//Checks stack values being added to ensure they are all digits
//Also checks stack values being added to ensure they are within INT limits
int				valid_type(ssize_t num);
//Checks stack values being added to ensure there are no duplicates
t_stack_node	*valid_dup(t_stack_node *lst);

/********************************************************
					Stack Operations
********************************************************/
//Pops first element at stack b and pushes it at the top of stack a
//(simply swaps top element between 2 stacks)
//does nothing if 2nd parameter (2nd stack) is empty
void			push(t_stack_node **stack_a, t_stack_node **stack_b, char *str);
//Swaps the first 2 elements of the given stack
//Does nothing if there is 1 or no elements
void			swap(t_stack_node **node, char *str);
//Rotate elements within a stack (first becomes last)
//EX. (1, 2, 3, 4, 5) --> (2, 3, 4, 5, 1)
void			rotate(t_stack_node **stack, char *str);
//Reverse rotate elements within a stack (last becomes first)
//EX. (1, 2, 3, 4, 5) --> (5, 1, 2, 3, 4)
void			reverse_rotate(t_stack_node **stack, char *str);
//Double rotate
void			rr(t_stack_node **stack_a, t_stack_node **stack_b);
//Double reverse rotate
void 			rrr(t_stack_node **stack_a, t_stack_node **stack_b);
//Rotates both stacks till cheap node is on top
void			rotate_till_first(t_stack_node **stack_a, t_stack_node **stack_b, 
			t_stack_node *cheap);
//Reverse rotates both stacks till cheap node is on top
void			rev_rotate_till_first(t_stack_node **stack_a, t_stack_node **stack_b, 
			t_stack_node *cheap);
//Rotates a single stack till target node is at the top of the stack
void			check_single_rotations(t_stack_node **stack, t_stack_node *target, char *str);

/********************************************************
				Push_swap Sorting functions
********************************************************/
//Manages all sorting functions
void			push_swap(t_stack_node **stack_a, t_stack_node **stack_b);
//Sorts small chunks that consist of 3 nodes
void			sort_small(t_stack_node **stack);
//Sorts medium chunks that consist of 5 or less nodes
void			sort_medium(t_stack_node **stack_a, t_stack_node **stack_b);
//Sorts big stacks greater than 3 nodes
void			sort_big(t_stack_node **stack_a, t_stack_node **stack_b);
//Checks if a stack is sorted
int				check_sorted(t_stack_node *stack);
//Returns the cheapest node within a stack
t_stack_node	*get_cheapest(t_stack_node **stack);
//Returns the 2nd cheapest node within a stack
t_stack_node	*get_next_cheapest(t_stack_node **stack, int current_cheapest);
//Move nodes to stack B till there are 5 nodes left in stack A
void			move_nodes(t_stack_node **stack_a, t_stack_node **stack_b);
//Refreshes stack index values, targets, and costs
void			refresh_stacks(t_stack_node **stack_a, t_stack_node **stack_b);
//Rotates to ensure the order of the stack is sorted
void			check_order(t_stack_node **stack);

/********************************************************
				Priority Management functions
********************************************************/
//Returns the node containing the biggest value in a stack
t_stack_node	*find_big_num(t_stack_node **stack);
//Returns the node containing the smallest value in a stack
t_stack_node	*find_small_num(t_stack_node **stack);
//Sets the target node based on best match for the next highest number
void			set_target(t_stack_node **stack, t_stack_node **target_stack);
//Sets the index values for all nodes of the given stack
void			set_index(t_stack_node **stack);
//Sets the cost of every node between nodes A and B.
//Assumes stack B is the main stack, with stack A being
//the stack with the target nodes.
void			set_cost(t_stack_node *stack_a, t_stack_node *stack_b);
//Checks for above_below value and rotates according to it
void			check_above_below(t_stack_node *node, t_stack_node *stack, char *str);

/********************************************************
			Utilities and other functions
********************************************************/
//Checks for permitted whitespace and signs
int				is_permitted(int c);
//Checks string for any forbidden characters
int				check_forbidden(char *str);
//Checks argv, joins it into a string, checks it for forbidden characters
//then splits it if it is valid, and returns the split strs as a 2d array
char			**create_values(char **argv);
//Frees the strs array
void			free_all(char **strs);
//Incase of an error, this will free all stacks and exit the program
void			error_out(t_stack_node *stack_a, t_stack_node *stack_b);

#endif
