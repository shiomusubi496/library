#define PROBLEM "https://judge.yosupo.jp/problem/longest_increasing_subsequence"
#include "../../../other/template.hpp"
#include "../../../string/LongestIncreasingSubsequence.hpp"
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> a(n); cin >> a;
    LongestIncreasingSubsequence<vector<int>> lis(a);
    cout << lis.size() << endl;
    cout << lis.get() << endl;
}
