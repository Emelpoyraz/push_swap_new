#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "../libft/libft.h"

typedef struct s_node
{
    int value;
    int index;
    struct s_node *next;
    
} t_node;
/* ============ PARSING ============ */
t_node  *parse_args(int argc, char **argv);
int is_valid_number(char *str);
int is_duplicate(t_node *stack, int value);
void	normalize_stack(t_node *stack);
long ft_atol(const char *str);
t_node *process_arg(char *arg, t_node *stack);

/* ============ STACK UTILS ============ */
t_node  *new_node(int value);
void    push_front(t_node **stack, t_node *new);
void    push_back(t_node **stack, t_node *new);
t_node  *pop_front(t_node **stack);
t_node  *last_node(t_node *stack);
int stack_size(t_node *stack);
int find_min_index(t_node *stack);
int get_max_position(t_node *stack);
void free_stack(t_node **stack);
void	rotate_smart(t_node **b);
void pa_smart(t_node **a, t_node **b);

/* ============ OPERATIONS ============ */
void    sa(t_node **a);
void    sb(t_node **b);
void    ss(t_node **a, t_node **b);
void    pa(t_node **a, t_node **b);
void    pb(t_node   **a, t_node **b);
void    ra(t_node **a);
void    rb(t_node **b);
void    rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

/* ============ SORTING ============ */
void    sort_under_six(t_node **a, t_node **b);
void    sort_fresh(t_node **a, t_node **b);

int	*find_lis(t_node *a, int size, int *lis_len);
void exit_error();
int validate_number(char *str, t_node *stack, char **split);
int is_sorted(t_node *stack);
void free_stack(t_node **stack);
void    free_split(char **split);
void    exit_error_safe(t_node **stack, char **split);
void	sort_fresh(t_node **a, t_node **b);
int	node_index(t_node *stack, t_node *target);
int	find_insert_position(t_node *a, int value);
int	rotation_cost(t_node *stack, int index);
void	execute_best_move(t_node **a, t_node **b, t_node *target);
int min_index(t_node *stack);
#endif