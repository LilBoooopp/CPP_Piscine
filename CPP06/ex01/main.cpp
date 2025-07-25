#include "Serializer.hpp"
#include <iostream>

int main() {
	Data* original = new Data(123, "forty-two");
	std::cout << "Original @ " << original << ": " << *original << std::endl;

	uintptr_t	raw = Serializer::serialize(original);
	std::cout << "Serialized to integer: " << raw << std::endl;

	Data*	restored = Serializer::deserialize(raw);
	std::cout << "Deserialized @ " << restored << ": " << *restored << std::endl;

	std::cout << (restored == original ? "Round-trip OK" : "ERROR: pointers differ") << std::endl;
	
	delete original;
	return (0);
}