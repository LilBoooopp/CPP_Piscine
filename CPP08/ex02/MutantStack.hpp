#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
	MutantStack(void) : std::stack<T, Container>() {}
	MutantStack(const MutantStack &other) : std::stack<T, Container>() {}
	MutantStack &operator=(const MutantStack &other) {
		if (this != &other) std::stack<T, Container>::operator=(other);
		return (*this);
	}
	~MutantStack(void) {}
	
	typedef class Container::iterator				iterator;
	typedef class Container::const_iterator			const_iterator;
	typedef class Container::reverse_iterator		reverse_iterator;
	typedef class Container::const_reverse_iterator	const_reverse_iterator;

	iterator begin() { return (this->c.begin()); }
	iterator end() { return (this->c.end()); }
	const_iterator begin() const { return (this->c.begin()); }
	const_iterator end() const { return (this->c.end()); }

	reverse_iterator rbegin() { return (this->c.rbegin()); }
	reverse_iterator rend() { return (this->c.rend()); }
	const_reverse_iterator rbegin() const { return (this->c.rbegin()); }
	const_reverse_iterator rend() const { return (this->c.rend()); }
};

#endif
