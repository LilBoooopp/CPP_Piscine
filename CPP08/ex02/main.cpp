#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main()
{
	std::cout << "Mutant Stack test" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);

		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		std::stack<int> s(mstack);
		(void)s;
	}

	std::cout << "std::list comparison (should print the same sequence)" << std::endl;
	{
		std::list<int>	lst;
		lst.push_back(5);
		lst.push_back(17);
		std::cout << lst.back() << std::endl;
		lst.pop_back();
		std::cout << lst.size() << std::endl;
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);

		lst.push_back(0);

		std::list<int>::iterator it = lst.begin();
		std::list<int>::iterator ite = lst.end();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
	}

	std::cout << "MutantStack reverse iteration" << std::endl;
	{
		MutantStack<int> ms;
		ms.push(1);
		ms.push(2);
		ms.push(3);
		for (MutantStack<int>::reverse_iterator rit = ms.rbegin(); rit != ms.rend(); ++rit) {
			std::cout << *rit << ' ';
		}
		std::cout << std::endl;
	}

	return 0;
}