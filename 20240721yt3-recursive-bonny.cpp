//      https://pro-prof.com/forums/topic/dynamic-progress-on_example
//
#include <iostream>

int count(int k, int n) {
  if (n == 0)
    return 1;

  int n_count = 0;
  for (int i = 1; i <= std::min(k, n); ++i) {
    n_count += count(k, n - i);
  }
  return n_count;
}

int main() {
  
  
  int k, n, res = 0;

  std::cin >> n >> k;

  std::cout << count(k, n);

  return 0;
}
