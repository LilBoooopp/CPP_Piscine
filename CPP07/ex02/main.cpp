#include <iostream>
#include <string>
#include "Array.hpp"

template <class T>
void	dump(const char* label, const Array<T>& a) {
	std::cout << label << " (size=" << a.size() << "): [";
	for (unsigned int i = 0; i < a.size(); ++i) {
		if (i) std::cout << ", ";
		std::cout << a[i];
	}
	std::cout << "]" << std::endl;
}

int main(void) {
	// Default construct
	Array<int> empty;
	std::cout << "empty.size() = " << empty.size() << std::endl;
	try { (void) empty[0]; } catch (const std::exception& e) {
		std::cout << "Accessing empty[0] throws: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Construct with n
	Array<int> ai(5);
	dump("ai (zeros)", ai);
	ai[2] = 42;
	ai[4] = -7;
	dump("ai (mutated)", ai);
	try { (void)ai[5]; } catch (const std::exception& e) {
		std::cout << "ai[5] throws: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Copy construct (deep)
	Array<int> bi(ai);
	dump("bi (copy of ai)", bi);
	ai[2] = 100;
	std::cout << "After ai[2]=100:" << std::endl;
	dump("ai", ai);
	dump("bi (must remain 42 at index 2)", bi);
	std::cout << std::endl;

	// Assignment (deep copy, size changes)
	Array<std::string> s1(3);
	s1[0] = "hello";
	s1[1] = "world";
	Array<std::string> s2;
	s2 = s1;
	s1[1] = "changed";
	dump("s1", s1);
	dump("s2 (must still be \"world\" at index 1)", s2);
	std::cout << std::endl;

	// Const access
	const Array<std::string> cs = s2;
	std::cout << "cs.size() = " << cs.size() << std::endl;
	std::cout << "cs[0] = " << cs[0] << std::endl;
	try { (void)cs[3]; } catch (const std::exception& e) {
		std::cout << "cs[3] throws: " << e.what() << std::endl;
	}

	return (0);
}