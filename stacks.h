#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_bench
{
	int		enabled;
	double	disorder;
	char	*strat_name;
	char	*complexity;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}	t_bench;

typedef struct s_stack
{
	int				value;
	int				rank;
	struct s_stack	*next;
}	t_stack;

// Stack operations
void	sa(t_stack **a, t_bench *bench, int print);
void	sb(t_stack **b, t_bench *bench, int print);
void	ss(t_stack **a, t_stack **b, t_bench *bench);
void	pa(t_stack **a, t_stack **b, t_bench *bench, int print);
void	pb(t_stack **a, t_stack **b, t_bench *bench, int print);
void	ra(t_stack **a, t_bench *bench, int print);
void	rb(t_stack **b, t_bench *bench, int print);
void	rr(t_stack **a, t_stack **b, t_bench *bench);
void	rra(t_stack **a, t_bench *bench, int print);
void	rrb(t_stack **b, t_bench *bench, int print);
void	rrr(t_stack **a, t_stack **b, t_bench *bench);

// List helpers & Memory
t_stack	*ft_lstnew(int value);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
int		stack_size(t_stack *stack);
void	free_stack(t_stack **stack);

// Parsing & Metrics
int		fill_stack(t_stack **a, int argc, char **argv);
int		ft_atoi(const char *str, int *value);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_check(int argc, char **argv	);
double	compute_disorder(t_stack *stack_a);
size_t        ft_strlen(char *str);
void        putnbr_fd(int n, int fd);

// Algorithms & Strategy Selection
void	strat_select(char *flag, t_stack **a, t_stack **b, t_bench *bench);
void	simple_alg(t_stack **a, t_stack **b, t_bench *bench);
void	medium_alg(t_stack **a, t_stack **b, t_bench *bench);
void	complex_alg(t_stack **a, t_stack **b, t_bench *bench);
void	print_benchmark(t_bench *b);
void	assign_ranks(t_stack *stack);
void        print_ops(t_bench *bench);
void        print_benchmark(t_bench *b);
#endif
