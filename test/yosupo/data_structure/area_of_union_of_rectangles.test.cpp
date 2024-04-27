#define PROBLEM "https://judge.yosupo.jp/problem/area_of_union_of_rectangles"
#include "../../../other/template.hpp"
#include "../../../data-struct/2D/AreaofUnionofRectangles.hpp"
using namespace std;
int main() {
    int N; scan >> N;
    vector<array<ll, 4>> A(N); scan >> A;
    prints(area_of_union_of_rectangles(A));
}
