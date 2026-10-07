/*я написал класс который по переданной ему
изначально функции делат вокруг этой функции декоратор,
а конкретнее для функции корень я написал обертку
которая проверяет что в нее поданно неотрицательное число
*/
#include <iostream>
#include <functional>

int sqrt(int a) {
    int l = 0, r = a + 1;
    while (r - l > 1) {
        int med = (l + r) / 2;
        if (med * med > a) {
            r = med;
        } else {
            l = med;
        }
    }
    return l;
}
class good_sqrt {
    std::function<int(int)> sol;

public:
    good_sqrt(std::function<int(int)> cur) {
        sol = cur;
    }
    int operator()(int a) {
        if (a < 0) {
            return - 1;
        }
        return sol(a);
    }
};

int main() {
    int n;
    std::cin >> n;
    good_sqrt func(sqrt);
    std::cout << func(n) << '\n';
}

