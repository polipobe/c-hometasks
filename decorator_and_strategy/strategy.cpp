/*
это пример функции стратегии где одна и та же функция ведет
себя по-разному в зависимости от передаваемых аргументов
я написал алгоритм сортировки который сортирует в зависимости
от компоратора*/
#include <iostream>
#include <functional>
#include <vector>

bool grow(int a, int b) {
    return a < b;
}
bool drop(int a, int b) {
    return a > b;
}
bool sum_cmp(int a, int b) {
    int s1 = 0, s2 = 0;
    a = abs(a);
    b = abs(b);
    while (a > 0) {
        s1 += a % 10;
        a /= 10;
    }
    while (b > 0) {
        s2 += b % 10;
        b /= 10;
    }
    return s1 < s2;
}
void sort(std::vector <int>& a, std::function <bool(int, int)> cmp) {
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            if (cmp(a[j + 1], a[j])) {
                std::swap(a[j], a[j + 1]);
            }
        }
    }
    for (int v : a) {
        std::cout << v << ' ';
    }
    std::cout << '\n';
}
int main() {
    int n;
    std::cin >> n;
    std::vector<int> val(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> val[i];
    }
    sort(val, drop);
    sort(val, grow);
    sort(val, sum_cmp);
}

