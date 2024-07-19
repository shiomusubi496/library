#define PROBLEM "https://judge.yosupo.jp/problem/longest_increasing_subsequence"
#include "../../../other/template.hpp"
#include "../../../string/LongestIncreasingSubsequence.hpp"
using namespace std;
int main() {
    int n; scan >> n;
    vector<int> a(n); scan >> a;
    LongestIncreasingSubsequence<vector<int>> lis(a);
    print << lis.size() << endl;
    print << lis.get() << endl;
}
