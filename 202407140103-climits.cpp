// climits.cpp --некоторые ограничения для целых чисел, Пратта, стр.90
#include <iostream>
#include <climits>

int main() {
	int n_int = INT_MAX;
	int n_int_min = INT_MIN;
	unsigned n_int_uns = UINT_MAX;
	std::cout << "int is " << sizeof(int) << " bytes, from "  << n_int_min << " to " << n_int << ". Unsigned to " << n_int_uns << ".\n";

	std::cout << "int min - 1 = " << n_int_min - 1 << ", and int max + 1 = " << n_int + 1 << ". Unsigned + 1 = " << n_int_uns + 1 << ".\n";

	short n_short_min = SHRT_MIN;
	short n_short_max = SHRT_MAX;
	unsigned short n_short_uns = USHRT_MAX;
	std::cout << "short is " << sizeof(short) << " (" << sizeof n_short_max << ") bytes, from " << SHRT_MIN << " to " << SHRT_MAX << ". Unsigned short to " << n_short_uns << ".\n";

	long long n_llong_min = LLONG_MIN;
	long long n_llong_max = LLONG_MAX;
	unsigned long long n_llong_uns = ULLONG_MAX;
	std::cout << "long long is " << sizeof(long long) << " bytes, from " << n_llong_min << " to " << n_llong_max << ". Unsigned to " << n_llong_uns << ".\n";

	std::cout << "char is " << CHAR_BIT << " bits = 1 byte, from " << CHAR_MIN << " to " << CHAR_MAX << ".\n";
	std::cout << "Signed char is from " << SCHAR_MIN << " to " << SCHAR_MAX << ".\n";
	std::cout << "Unsigned char is  to " << UCHAR_MAX << ".\n";
}
