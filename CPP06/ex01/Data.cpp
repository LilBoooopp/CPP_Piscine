#include "Data.hpp"

std::ostream& operator<<(std::ostream& os, const Data& d) {
	return os << "Data { n=" << d.n << ", message=\"" << d.message << "\" }";
}
