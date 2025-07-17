#include <iostream>
void binary_output(int number) {
   std::cout << '\n' + std::string(10, '-') + '\n';
   std::cout << "2³ 2² 2¹ 2⁰ \n";
   std::cout << (number & 8) << "  " << (number & 4) << "  " << (number & 2)
             << "  " << (number & 1);
   std::cout << '\n' + std::string(10, '-') + '\n';
}
void and_function(int a, int b) {
   int result = a & b;
   std::cout << " a = " << a;
   binary_output(a);
   std::cout << " b = " << b;
   binary_output(b);
   std::cout << " a & b = " << result;
   binary_output(result);
}
void or_function(int a, int b) {
   int result = a | b;
   std::cout << " a = " << a;
   binary_output(a);
   std::cout << " b = " << b;
   binary_output(b);
   std::cout << " a | b = " << result;
   binary_output(result);
}
void xor_function(int a, int b) {
   int result = a ^ b;
   std::cout << " a = " << a;
   binary_output(a);
   std::cout << " b = " << b;
   binary_output(b);
   std::cout << " a ^ b = " << result;
   binary_output(result);
}
void not_function(int a) {
   int result = ~a;
   std::cout << " a = " << a;
   binary_output(a);
   std::cout << " ~a = " << result;
   binary_output(result);
}
void shift_right_function(int a, int b) {
   int result = a >> b;
   std::cout << " a = " << a;
   binary_output(a);
   std::cout << " b = " << b;
   binary_output(b);
   std::cout << " a >> b = " << result;
   binary_output(result);
}
void shift_left_function(int a, int b) {
   int result = a << b;
   std::cout << " a = " << a;
   binary_output(a);
   std::cout << " b = " << b;
   binary_output(b);
   std::cout << " a << b = " << result;
   binary_output(result);
}

int main() {
   {
       std::cout << "\tAnd\t\n";
       int a = 5;
       int b = 15;
       and_function(a, b);
   }
   {
       std::cout << "\tOr\t\n";
       int a = 64;
       int b = 32;
       or_function(a, b);
   }
   {
       std::cout << "\tXor\t\n";
       int a = 5;
       int b = 15;
       xor_function(a, b);
   }
   {
       std::cout << "\tNot\t\n";
       int a = 17;
       not_function(a);
   }
   {
       std::cout << "\tShift >>\t\n";
       int a = 5;
       int b = 2;
       shift_right_function(a, b);
   }
   {
       std::cout << "\tShift <<\t\n";
       int a = 5;
       int b = 2;
       shift_left_function(a, b);
   }
   return 0;
}
