#ifndef STACK_H

# define STACK_H

#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack
{
    int value;
    struct s_stack *next;
}  t_stack;

#endif
