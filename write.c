#include "stacks.h"

void        putnbr_fd(int n, int fd)
{
        char        c;

        if (n >= 10)
                putnbr_fd(n / 10, fd);
        c = (n % 10) + '0';
        write(fd, &c, 1);
}

void        print_ops(t_bench *bench)
{
    write(2, "[bench] sa: ", 12);
    putnbr_fd(bench->sa, 2);
    write(2, " sb: ", 5);
    putnbr_fd(bench->sb, 2);
    write(2, " ss: ", 5);
    putnbr_fd(bench->ss, 2);
    write(2, " pa: ", 5);
    putnbr_fd(bench->pa, 2);
    write(2, " pb: ", 5);
    putnbr_fd(bench->pb, 2);
    write(2, "\n[bench] ra: ", 13);
    putnbr_fd(bench->ra, 2);
    write(2, " rb: ", 5);
    putnbr_fd(bench->rb, 2);
    write(2, " rr: ", 5);
    putnbr_fd(bench->rr, 2);
    write(2, " rra: ", 6);
    putnbr_fd(bench->rra, 2);
    write(2, " rrb: ", 6);
    putnbr_fd(bench->rrb, 2);
    write(2, " rrr: ", 6);
    putnbr_fd(bench->rrr, 2);
}

size_t        ft_strlen(char *str)
{
        int        i;

        i = 0;
        while (str[i])
                i++;
        return (i);
}

void        print_benchmark(t_bench *b)
{
        int        total;
        int        whole;
        int        frac;

        total = b->sa + b->sb + b->ss + b->pa + b->pb
                        + b->ra + b->rb + b->rr + b->rra + b->rrb + b->rrr;
        whole = (int)(b->disorder * 100);
        frac = (int)((b->disorder * 100 - whole) * 100);
        write (2, "[bench] disorder: ", 18);
        putnbr_fd(whole, 2);
        write (2, ".", 1);
        if (frac < 10)
                write (2, "0", 1);
        putnbr_fd(frac, 2);
        write (2, "%\n[bench] strategy: ", 20);
        write (2, b->strat_name, ft_strlen(b->strat_name));
        write (2, " / ", 3);
        write (2, b->complexity, ft_strlen(b->complexity));
        write (2, "\n[bench] total_ops: ", 20);
        putnbr_fd(total, 2);
        write (2, "\n", 1);
        print_ops(b);
}
