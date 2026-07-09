/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */

#include "solution.hpp"

#include <gtest/gtest.h>

#include <vector>

TEST(ProductOfArrayExceptSelf, Example1) {
    dv::lc::Solution s;
    EXPECT_EQ((std::vector<int>{24, 12, 8, 6}), s.productExceptSelf({1, 2, 3, 4}));
}

TEST(ProductOfArrayExceptSelf, Example2) {
    dv::lc::Solution s;
    EXPECT_EQ((std::vector<int>{0, 0, 9, 0, 0}), s.productExceptSelf({-1, 1, 0, -3, 3}));
}

TEST(ProductOfArrayExceptSelf, SingleZero) {
    dv::lc::Solution s;
    EXPECT_EQ((std::vector<int>{6, 0, 0, 0}), s.productExceptSelf({0, 1, 2, 3}));
}

TEST(ProductOfArrayExceptSelf, MultipleZeros) {
    dv::lc::Solution s;
    EXPECT_EQ((std::vector<int>{0, 0, 0, 0}), s.productExceptSelf({0, 2, 0, 4}));
}

TEST(ProductOfArrayExceptSelf, TwoElements) {
    dv::lc::Solution s;
    EXPECT_EQ((std::vector<int>{5, 7}), s.productExceptSelf({7, 5}));
}

TEST(ProductOfArrayExceptSelf, NegativeNumbers) {
    dv::lc::Solution s;
    EXPECT_EQ((std::vector<int>{216, -144, 108, -72, 144}), s.productExceptSelf({-2, 3, -4, 6, -3}));
}
