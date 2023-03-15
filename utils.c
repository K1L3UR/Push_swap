#include "push_swap.h"

int ft_error(int a)
{
    if (a == 0)
        exit(0);
    if (a == -1)
        exit((ft_putendl_fd("Wrong numbers of arguments", 1), -1));
    if (a == -2)
        exit(-2);
    if (a == -3)
        exit(-3);
    if (a == -4)
        exit(-4);
    EXIT_FAILURE;
}