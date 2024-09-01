#include <iostream>

int main() {
	int a = 1; // C
	int b = a + 1;
	int c(3); // C++
	int d {4}; // C++11
	int e = {5}; //C++11
	int f {};
	std::cout << a << " " << b << " " << c << " " << d << " " << e << " " << f <<  "\n";
    std::cout << sizeof(a) << "\n";
}
