#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iterator>
#include <cstddef>

class Span {
	private:
		unsigned int		_capacity;
		std::vector<int>	_data;
	public:
		explicit Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span(void);

		void	addNumber(int value);

		template <class InputIt>
		void	addRange(InputIt first, InputIt last) {
			std::size_t count = std::distance(first, last);
			if (_data.size() + count > _capacity) {
				throw FullException();
			}
			_data.insert(_data.end(), first, last);
		}

		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;

		std::size_t	size() const { return _data.size(); }
		unsigned int capacity() const { return _capacity; }

		struct FullException : public std::exception {
			const char* what() const throw() { return "Span: capacity reached"; }
		};
		struct NoSpanException : public std::exception {
			const char* what() const throw() { return "Span: not enough elements for a span"; }
		};
};

#endif
