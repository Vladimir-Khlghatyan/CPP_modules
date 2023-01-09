#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

# define BLACK	"\33[1;30m"
# define RED	"\33[1;31m"
# define GREEN	"\33[1;32m"
# define YELLOW	"\33[1;33m"
# define BLUE	"\33[1;34m"
# define PINK	"\33[1;35m"
# define CYAN	"\33[1;36m"
# define WHITE	"\33[1;37m"
# define RESET	"\33[0;m"

template <typename T>
void    swap(T& a, T& b)
{
    T   tmp;

    tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T   max(T& a, T& b)
{
    return (a > b ? a : b);
}

template <typename T>
T   min(T& a, T& b)
{
    return (a < b ? a : b);
}

#endif
