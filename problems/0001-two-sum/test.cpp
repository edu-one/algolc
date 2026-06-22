/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */

#include "solution.hpp"

#include <gtest/gtest.h>

#include <vector>

TEST(TwoSum, Example1) {
    dv::lc::Solution s;
    EXPECT_EQ((std::vector<int>{0, 1}), s.twoSum({2, 7, 11, 15}, 9));
}

TEST(TwoSum, Example2) {
    dv::lc::Solution s;
    EXPECT_EQ((std::vector<int>{1, 2}), s.twoSum({3, 2, 4}, 6));
}

TEST(TwoSum, SameValueTwice) {
    dv::lc::Solution s;
    EXPECT_EQ((std::vector<int>{0, 1}), s.twoSum({3, 3}, 6));
}
