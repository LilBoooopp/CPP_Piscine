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
			typedef typename std::iterator_traits<InputIt>::difference_type diff_t;
			diff_t	diff = std::distance(first, last);
			if (diff < 0) diff = 0;

			const std::size_t count = static_cast<std::size_t>(diff);
			const std::size_t curr = _data.size();
			const std::size_t cap = static_cast<std::size_t>(_capacity);

			if (curr + count > cap)
				throw FullException();
			
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
