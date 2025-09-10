#include "Array.hpp"

template <class T>
Array<T>::Array() : _data(0), _n(0) {}

template <class T>
Array<T>::Array(unsigned int n) : _data(0), _n(n) {
	_data = (_n ? new T[_n]() : 0);
}

template <class T>
Array<T>::Array(const Array& other) : _data(0), _n(other._n) {
	_data = (_n ? new T[_n] : 0);
	for (unsigned int i = 0; i < _n; ++i)
		_data[i] = other._data[i];
}

template <class T>
Array<T>::~Array() {
	delete[] _data;
}

template <class T>
void	Array<T>::swap(Array& other) {
	T*	tmpData = _data;
	_data = other._data;
	other._data = tmpData;
	unsigned int tmpN = _n;
	_n = other._n;
	other._n = tmpN;
}

template <class T>
Array<T>& Array<T>::operator=(const Array& other) {
	if (this != &other) {
		Array tmp(other);
		swap(tmp);
	}
	return (*this);
}

template <class T>
T& Array<T>::operator[](unsigned int idx) {
	if (idx >= _n) throw std::out_of_range("Array::operator[]: index out of bounds");
	return (_data[idx]);
}

template <class T>
const T& Array<T>::operator[](unsigned int idx) const {
	if (idx >= _n) throw std::out_of_range("Array::operator const: index out of bounds");
	return (_data[idx]);
}

template <class T>
unsigned int Array<T>::size() const {
	return (_n);
}
