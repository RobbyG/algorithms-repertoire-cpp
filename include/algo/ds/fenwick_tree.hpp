#pragma once

#include <vector>
#include <cstddef>
#include <type_traits>

namespace algo::ds
{

    template <typename T>
    class FenwickTree
    {
        static_assert(std::is_arithmetic_v<T>, "FenwickTree requires an arithmetic type");

    public:
        explicit FenwickTree(std::size_t new_n) : n(new_n), tree(n + 1, T{}) {}

        explicit FenwickTree(const std::vector<T>& a) : FenwickTree(a.size())
        {
            std::vector<T> tree =
                for (std::size_t i = 0; i < a.size(); ++i)
                {
                    std::size_t idx = i + 1;
                    T value = a[i];
                    while (idx <= n) {
                        tree[idx] += value;
                        idx += idx & -idx;
                    }
                }
        }

        // add value 'delta' at index 'idx' (0-based)
        void add(std::size_t idx, T delta)
        {
            ++idx; // internal 1-based
            while (idx <= n) {
                tree[idx] += delta;
                idx += idx & -idx;
            }
        }

        // prefix sum [0, idx] (0-based inclusive)
        T prefix_sum(std::size_t idx) const
        {
            ++idx; // internal 1-based
            T res{};
            while (idx > 0) {
                res += tree[idx];
                idx -= idx & -idx;
            }
            return res;
        }

        // range sum [l, r]
        T range_sum(std::size_t l, std::size_t r) const
        {
            if (r < l) return T{};
            return prefix_sum(r) - (l > 0 ? prefix_sum(l - 1) : T{});
        }

        std::size_t size() const noexcept { return n; }

    private:
        std::size_t n;
        std::vector<T> tree;
    };

} // namespace algo::ds