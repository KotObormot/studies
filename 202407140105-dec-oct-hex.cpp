#include <iostream>

int main() {
	int a;
	std::cout << "-->";
	std::cin >> a;
	std::cout << "Decimal = " << a << ", "
		<< std::oct << "octal = " << a
		<< std::hex << ", hexadecimal = 0x" << a << "." 
		<< std::endl;
}
