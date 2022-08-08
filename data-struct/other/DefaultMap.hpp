#pragma once

#include "../../other/template.hpp"

template<class Key, class T, class Comp = std::less<Key>,
         class Alloc = std::allocator<std::pair<const Key, T>>>
class default_map : public std::map<Key, T, Comp, Alloc> {
private:
    using base = std::map<Key, T, Comp, Alloc>;
    T default_value;

public:
    default_map(const T& default_value, const Comp& comp = Comp(),
                const Alloc& alloc = Alloc())
        : base(comp, alloc), default_value(default_value) {}
    template<class InputIterator>
    default_map(InputIterator first, InputIterator last, const T& default_value,
                const Comp& comp = Comp(), const Alloc& alloc = Alloc())
        : base(first, last, comp, alloc), default_value(default_value) {}
    default_map(std::initializer_list<typename base::value_type> init,
                const T& default_value, const Comp& comp = Comp(),
                const Alloc& alloc = Alloc())
        : base(init, comp, alloc), default_value(default_value) {}
    default_map(const default_map& other)
        : base(other), default_value(other.default_value) {}
    default_map(default_map&& other)
        : base(move(other)), default_value(std::move(other.default_value)) {}
    T& operator[](const Key& key) {
        auto itr = this->lower_bound(key);
        if (itr == this->end() || this->key_comp()(key, itr->first)) {
            itr = this->emplace_hint(itr, key, default_value);
        }
        return itr->second;
    }
    T& operator[](Key&& key) {
        auto itr = this->lower_bound(key);
        if (itr == this->end() || this->key_comp()(key, itr->first)) {
            itr = this->emplace_hint(itr, std::move(key), default_value);
        }
        return itr->second;
    }
    T& at(const Key& key) {
        auto itr = this->find(key);
        if (itr == this->end() || this->key_comp()(key, itr->first)) {
            throw std::out_of_range("key not found");
        }
        return itr->second;
    }
    const T& at(const Key& key) const {
        auto itr = this->find(key);
        if (itr == this->end() || this->key_comp()(key, itr->first)) {
            throw std::out_of_range("key not found");
        }
        return itr->second;
    }
};

/**
 * @brief DefaultMap
 * @docs docs/DefaultMap.md
 */
