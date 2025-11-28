#pragma once

#include <vector>
#include <cstddef>
#include <type_traits>

namespace algo::ds {

    template <typename T>
    class FenwickTree {
        static_assert(std::is_arithmetic_v<T>, "FenwickTree requires an arithmetic type");

    public:
        explicit FenwickTree(std::size_t n)
            : n_(n), bit_(n + 1, T{}) {
        }

        explicit FenwickTree(const std::vector<T>& a)
            : FenwickTree(a.size()) {
            for (std::size_t i = 0; i < a.size(); ++i) {
                add(i, a[i]);
            }
        }

        // add value 'delta' at index 'idx' (0-based)
        void add(std::size_t idx, T delta) {
            ++idx; // internal 1-based
            while (idx <= n_) {
                bit_[idx] += delta;
                idx += idx & -idx;
            }
        }

        // prefix sum [0, idx] (0-based inclusive)
        T prefix_sum(std::size_t idx) const {
            ++idx; // internal 1-based
            T res{};
            while (idx > 0) {
                res += bit_[idx];
                idx -= idx & -idx;
            }
            return res;
        }

        // range sum [l, r]
        T range_sum(std::size_t l, std::size_t r) const {
            if (r < l) return T{};
            return prefix_sum(r) - (l > 0 ? prefix_sum(l - 1) : T{});
        }

        std::size_t size() const noexcept { return n_; }

    private:
        std::size_t n_;
        std::vector<T> bit_;
    };

} // namespace algo::ds
