#include <cassert>
#include <cstddef>
#include <vector>
#include <iostream>

#include "algo/ds/fenwick_tree.hpp"

using algo::ds::FenwickTree;

void test_initially_zero() {
    FenwickTree<int> ft(5);
    for (std::size_t i = 0; i < 5; ++i) {
        assert(ft.prefix_sum(i) == 0);
    }
    assert(ft.range_sum(0, 4) == 0);
}

void test_basic_updates() {
    FenwickTree<int> ft(5);
    ft.add(0, 1);
    ft.add(1, 2);
    ft.add(2, 3);

    assert(ft.prefix_sum(0) == 1);
    assert(ft.prefix_sum(1) == 3);
    assert(ft.prefix_sum(2) == 6);

    assert(ft.range_sum(0, 2) == 6);
    assert(ft.range_sum(1, 2) == 5);
    assert(ft.range_sum(2, 2) == 3);
}

void test_from_vector_constructor() {
    std::vector<long long> a{ 1, 2, 3, 4 };
    FenwickTree<long long> ft(a);

    assert(ft.prefix_sum(0) == 1);
    assert(ft.prefix_sum(1) == 3);
    assert(ft.prefix_sum(2) == 6);
    assert(ft.prefix_sum(3) == 10);

    assert(ft.range_sum(1, 3) == 9);
}

void test_weird_ranges() {
    FenwickTree<int> ft(5);
    // r < l should be zero by our design
    assert(ft.range_sum(3, 1) == 0);
}

int main() {
    test_initially_zero();
    test_basic_updates();
    test_from_vector_constructor();
    test_weird_ranges();

    std::cout << "All FenwickTree tests passed.\n";
    return 0;
}
