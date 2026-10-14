#include <algorithm>
#include <iomanip>
#include <iostream>

struct pair {
  int a, b;
  pair(int a_, int b_):a{a_}, b{b_}{ }
};

double get_avg(const int n, const int* val) {
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += val[i];
  }
  return (1.0 * sum) / n;
}
pair get_min_and_max(const int n, const int* val) {
  int mx = val[0], mn = val[0];
  for (int i = 0; i < n; ++i) {
    mx = std::max(mx, val[i]);
    mn = std::min(mn, val[i]);
  }
  return {mn, mx};
}
int count_below_zero(const int n, const int* val) {
  int counter = 0;
  for (int i = 0; i < n; ++i) {
    if (val[i] < 0) {
      ++counter;
    }
  }
  return counter;
}
signed main() {
  std::cout << std::setprecision(1) << std::fixed;
  int n;
  std::cin >> n;
  int* val = new int [n];
  for (int i = 0; i < n; ++i) {
    std::cin >> val[i];
  }
  std::cout << get_avg(n, val) << '\n';
  pair res = get_min_and_max(n, val);
  std::cout << res.a << " " << res.b << '\n';
  std::cout << count_below_zero(n, val) << '\n';
  delete[] val;
}

