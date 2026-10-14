#include <cstring>
#include <iomanip>
#include <iostream>

void deposite(int &sum) {
  int k;
  std::cin >> k;
  if (k <= 0) {
    std::cout << "error\n";
    return;
  }
  sum += k;
}
void withdraw(int &sum) {
  int k;
  std::cin >> k;
  if (k <= 0 || k > sum) {
    std::cout << "error\n";
    return;
  }
  sum -= k;
}
void balance(int &sum) {
  std::cout << sum << '\n';
}
void reset(int &sum) {
  sum = 0;
}
void doubl(int &sum) {
  sum *= 2;
}
signed main() {
  const char* type[] = {"deposit", "withdraw", "balance", "reset", "double"};
  void(*query[])(int&) = {deposite, withdraw, balance, reset, doubl};
  char comand[10];
  std::cin >>  std::setw(10) >> comand;
  int sum = 0;
  while (std::strcmp(comand, "stop") != 0) {
    bool flag = false;
    for (int i = 0; i < sizeof(query) / sizeof(query[0]); ++i) {
      if (std::strcmp(comand, type[i]) == 0) {
        query[i](sum);
        flag = true;
      }
    }
    if (!flag) {
      std::cout << "error\n";
    }
    std::cin >>  std::setw(10) >> comand;
  }
}

