#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"
#include "../../template.cpp"
int main() {
    int T;
    std::cin >> T;
    while (T--) {
        int a, b;
        std::cin >> a >> b;
        std::cout << a + b << std::endl;
    }
}
