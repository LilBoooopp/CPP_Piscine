#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <class T>
class Array {
public:
	Array();
	explicit Array(unsigned int n);
	Array(const Array& other);
	~Array();

	Array& operator=(const Array& other);

	T& operator[](unsigned int idx);
	const T& operator[](unsigned int idx) const;

	unsigned int size() const;

	void swap(Array& other);

private:
	T*				_data;
	unsigned int	_n;
};

#include "Array.tpp"
#endif