#pragma once

#include "../other/template.hpp"

class BarrettReduction {
private:
    unsigned int m;
    unsigned long long im;

public:
    BarrettReduction(unsigned int m_)
        : m(m_), im((unsigned long long)(-1) / m + 1) {}

    inline void set_mod(unsigned int m_) {
        m = m_;
        im = (unsigned long long)(-1) / m + 1;
    }

    inline unsigned int get_mod() const { return m; }

    unsigned int reduce(ull a) const {
        ull x = static_cast<ull>((static_cast<__uint128_t>(a) * im) >> 64);
        unsigned int v = static_cast<unsigned int>(a - x * static_cast<ull>(m));
        return v >= m ? v + m : v;
    }

    unsigned int rem(ull a) const { return reduce(a); }

    ull quo(ull a) const {
        ull x = static_cast<ull>((static_cast<__uint128_t>(a) * im) >> 64);
        unsigned int v = static_cast<unsigned int>(a - x * static_cast<ull>(m));
        return v >= m ? x - 1 : x;
    }

    unsigned int mul(unsigned int a, unsigned int b) const {
        return reduce(static_cast<ull>(a) * b);
    }
};
