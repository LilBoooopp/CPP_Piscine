#include "Span.hpp"

Span::Span(unsigned int N) : _capacity(N), _data()
{
	_data.reserve(N);
}

Span::Span(const Span &other)
: _capacity(other._capacity), _data(other._data) {}

Span &Span::operator=(const Span &other)
{
	if (this != &other) {
		_capacity = other._capacity;
		_data = other._data;
	}
	return (*this);
}

Span::~Span(void) {}

void	Span::addNumber(int value)
{
	if (_data.size() >= static_cast<std::size_t>(_capacity))
		throw FullException();
	_data.push_back(value);
}

unsigned int	Span::shortestSpan() const
{
	if (_data.size() < 2u)
		throw NoSpanException();

	std::vector<int> tmp(_data);
	std::sort(tmp.begin(), tmp.end());

	unsigned int best = static_cast<unsigned int>(
		tmp[1] - tmp[0] >= 0 ? tmp[1] - tmp[0] : -(tmp[1] - tmp[0])
	);
	for (std::size_t i = 1; i + 1 < tmp.size(); ++i)
	{
		int diff = tmp[i+1] - tmp[i];
		unsigned int span = static_cast<unsigned int>(diff);
		if (span < best) best = span;
		if (best == 0u) break;
	}
	return (best);
}

unsigned int	Span::longestSpan() const {
	if (_data.size() < 2u)
		throw NoSpanException();
	
	std::vector<int>::const_iterator mn = std::min_element(_data.begin(), _data.end());
	std::vector<int>::const_iterator mx = std::max_element(_data.begin(), _data.end());

	const int diff = *mx - *mn;
	return (static_cast<unsigned int>(diff));
}
