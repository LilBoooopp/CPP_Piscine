#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP

template <class T>
void	swap(T& a, T& b)
{
	T	temp = a;
	a = b;
	b = temp;
}

template <class T>
const T&	min(T& a, T& b)
{
	return (a < b ? a : b);
}

template <class T>
const T&	max(T& a, T& b)
{
	return (a > b ? a : b);
}

#endif