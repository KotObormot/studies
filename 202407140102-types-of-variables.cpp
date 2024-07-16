#include <iostream>

int main () {
	unsigned int aU  = 2;
	int a = -2; // 4 байта
	unsigned long long bU = 2586970; // 8 байт
	long long c = -9829650967; // 8 байт
	unsigned short dU = 587;
	short d = -586; // 2 байта
	signed char eU = -'e'; // 1 байт
	char e = 'e';
	
	std::cout << a * 2 << " "  << " " << c * 2 << " " << d * 2 << " " << e * 2 << "\n";
	std::cout << aU * 3 << " " << bU * 3 << " " << dU * 2 << " " << eU + e << "\n";
}
