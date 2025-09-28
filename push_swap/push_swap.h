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

t_node  *parse_args(int argc, char **argv);
int is_valid_number(char *str);
int is_duplicate(t_node *stack, int value);
void    exit_error(void);

// Stack utils
t_node  *new_node(int value);
void    push_front(t_node **stack, t_node *new);
void    push_back(t_node **stack, t_node *new);
t_node  *pop_front(t_node **stack);
t_node  *last_node(t_node *stack);
int stack_size(t_node *stack);
int find_min_index(t_node *stack);
void	normalize_stack(t_node *stack);
int	get_chunk_count(int size);
void free_stack(t_node **stack);

//Instructions
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

//sort utils
int get_max_position(t_node *stack);
void pa_smart(t_node **a, t_node **b);

//Sorting starts
void	sort_under_six(t_node **a, t_node **b);
void	sort_small_medium_stack(t_node **a, t_node **b);  // 6–100
void	sort_large_huge_stack(t_node **a, t_node **b);   // 101+

void	sort_all(t_node **a, t_node **b);


#endif