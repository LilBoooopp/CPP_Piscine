#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>
template <class T>
void	iter(T* a, std::size_t n, void (*f)(T&))
{
	if (!a) return ;
	for (std::size_t i = 0; i < n; ++i) f(a[i]);
}

template <class T>
void	iter(T* a, std::size_t n, void (*f)(const T&))
{
	if (!a) return ;
	for (std::size_t i = 0; i < n; ++i) f(a[i]);
}

template <class T>
void	iter(const T* a, std::size_t n, void (*f)(const T&))
{
	if (!a) return ;
	for (std::size_t i = 0; i < n; ++i) f(a[i]);
}

#endif