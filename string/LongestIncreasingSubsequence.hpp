#pragma once

#include "../other/template.hpp"

template<class Cont>
// using Cont = std::string;
class LongestIncreasingSubsequence {
protected:
    using T = typename Cont::value_type;
    std::vector<int> lis;

public:
    LongestIncreasingSubsequence(const Cont& str, bool strict = true) {
        int n = str.size();
        std::vector<int> dp(n + 1, -1);
        // dp[i] : 長さ i の単調増加数列の最後の要素で最小のものの index
        dp[0] = -2;
        auto cmp = [&](int i, int j) {
            if (i == -1 || j == -2) return false;
            if (j == -1 || i == -2) return true;
            return str[i] < str[j];
        };
        std::vector<int> prv(n, -1);
        rep (i, n) {
            auto itr = strict ? std::lower_bound(all(dp), i, cmp)
                              : std::upper_bound(all(dp), i, cmp);
            prv[i] = itr == dp.begin() ? -1 : *(itr - 1);
            *itr = i;
        }
        int len = 0, lst = -1;
        reps (i, n) {
            if (dp[i] != -1) {
                len = i;
                lst = dp[i];
            }
            else break;
        }
        lis.resize(len);
        int cur = lst;
        while (cur >= 0) {
            lis[--len] = cur;
            cur = prv[cur];
        }
    }
    int size() const { return lis.size(); }
    const std::vector<int>& get() const& { return lis; }
    std::vector<int> get() && { return std::move(lis); }
    std::vector<T> get_str(const Cont& str) const {
        std::vector<T> res(size());
        rep (i, size()) res[i] = str[lis[i]];
        return res;
    }
};

/**
 * @brief LongestIncreasingSubsequence(LIS,最長増加部分列)
 * @docs docs/LongestIncreasingSubsequence.md
 */
