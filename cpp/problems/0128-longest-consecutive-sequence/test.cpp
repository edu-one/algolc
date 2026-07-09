/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */

#include "solution.hpp"

#include <gtest/gtest.h>

#include <vector>

namespace {

int longestConsecutive(const std::vector<int> &nums) {
    dv::lc::Solution solution;
    return solution.longestConsecutive(nums);
}

} // namespace

TEST(LongestConsecutiveSequence, Example1UnsortedWithGap) {
    EXPECT_EQ(longestConsecutive({100, 4, 200, 1, 3, 2}), 4);
}

TEST(LongestConsecutiveSequence, Example2FullRun) {
    EXPECT_EQ(longestConsecutive({0, 3, 7, 2, 5, 8, 4, 6, 0, 1}), 9);
}

TEST(LongestConsecutiveSequence, Example3DuplicatesIgnored) {
    EXPECT_EQ(longestConsecutive({1, 0, 1, 2}), 3);
}

TEST(LongestConsecutiveSequence, EmptyInput) {
    EXPECT_EQ(longestConsecutive({}), 0);
}

TEST(LongestConsecutiveSequence, SingleElement) {
    EXPECT_EQ(longestConsecutive({42}), 1);
}

TEST(LongestConsecutiveSequence, AllSameElement) {
    EXPECT_EQ(longestConsecutive({5, 5, 5, 5}), 1);
}

TEST(LongestConsecutiveSequence, NoConsecutivePairs) {
    EXPECT_EQ(longestConsecutive({10, 30, 20, 50}), 1);
}

TEST(LongestConsecutiveSequence, NegativeAndPositiveRun) {
    EXPECT_EQ(longestConsecutive({-2, -1, 0, 1, -3}), 5);
}
