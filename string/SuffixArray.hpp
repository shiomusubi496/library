#pragma once

#include "../other/template.hpp"

namespace internal {

template<class Cont>
std::vector<int> sa_is(const Cont& str, int m) {
    int n = str.size();
    if (n == 0) return {};
    if (n == 1) return {0};
    if (n == 2) {
        if (str[0] < str[1]) return {0, 1};
        return {1, 0};
    }

    std::vector<int> sa(n);
    std::vector<bool> ls(n);
    ls[n - 1] = 0;
    rrep (i, n - 1) {
        if (str[i] < str[i + 1]) ls[i] = 1;
        else if (str[i] > str[i + 1]) ls[i] = 0;
        else ls[i] = ls[i + 1];
    }

    std::vector<int> sml(m + 1), sms(m + 1);
    rep (i, n) {
        if (ls[i]) ++sml[str[i] + 1];
        else ++sms[str[i]];
    }
    rep (i, m + 1) {
        sms[i] += sml[i];
        if (i < m) sml[i + 1] += sms[i];
    }
    auto induce_sort = [&](const std::vector<int>& lms) {
        std::fill(all(sa), -1);
        std::vector<int> buf = sms;
        for (auto d : lms) {
            if (d == n) continue;
            sa[buf[str[d]]++] = d;
        }
        buf = sml;
        sa[buf[str[n - 1]]++] = n - 1;
        rep (i, n) {
            int t = sa[i];
            if (t >= 1 && !ls[t - 1]) sa[buf[str[t - 1]]++] = t - 1;
        }
        buf = sml;
        rrep (i, n) {
            int t = sa[i];
            if (t >= 1 && ls[t - 1]) sa[--buf[str[t - 1] + 1]] = t - 1;
        }
    };
    std::vector<int> rlms(n + 1, -1);
    int k = 0;
    rep (i, 1, n) {
        if (!ls[i - 1] && ls[i]) rlms[i] = k++;
    }
    std::vector<int> lms;
    lms.reserve(k);
    rep (i, 1, n) {
        if (!ls[i - 1] && ls[i]) lms.push_back(i);
    }
    induce_sort(lms);

    if (k) {
        std::vector<int> lms2;
        lms2.reserve(k);
        for (auto d : sa) {
            if (rlms[d] != -1) lms2.push_back(d);
        }
        std::vector<int> rec_s(k);
        int rec_m = 0;
        rec_s[rlms[lms2[0]]] = 0;
        rep (i, 1, k) {
            int l = lms2[i - 1], r = lms2[i];
            int l2 = (rlms[l] + 1 < k) ? lms[rlms[l] + 1] : n;
            int r2 = (rlms[r] + 1 < k) ? lms[rlms[r] + 1] : n;
            bool flag = true;
            if (l2 - l != r2 - r) flag = false;
            else {
                while (l < l2) {
                    if (str[l] != str[r]) break;
                    ++l, ++r;
                }
                if (l == n || str[l] != str[r]) flag = false;
            }
            if (!flag) ++rec_m;
            rec_s[rlms[lms2[i]]] = rec_m;
        }
        auto rec_sa = sa_is(rec_s, rec_m);
        rep (i, k) lms2[i] = lms[rec_sa[i]];
        induce_sort(lms2);
    }
    return sa;
}

}

template<class Cont>
std::vector<int> suffix_array(const Cont& str, int m) {
    return internal::sa_is(str, m + 1);
}
template<class Cont>
std::vector<int> suffix_array(const Cont& str) {
    std::vector<typename Cont::value_type> s(all(str));
    compressor<typename Cont::value_type> cmp(s, true);
    return internal::sa_is(cmp.pressed(s), cmp.size());
}
template<>
std::vector<int> suffix_array(const std::string& str) {
    return internal::sa_is(str, 256);
}

/**
 * @brief SuffixArray
 * @docs docs/string/SuffixArray.md
 */
