#ifndef STACK_H

# define STACK_H

struct typedef stack_s
{
    int *digit;
    struct stack_s *next;
}  stack;