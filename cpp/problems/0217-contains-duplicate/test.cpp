/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */

#include "solution.hpp"

#include <gtest/gtest.h>

#include <vector>

TEST(ContainsDuplicate, Example1DuplicatePresent) {
    dv::lc::Solution s;
    std::vector<int> nums{1, 2, 3, 1};
    EXPECT_TRUE(s.containsDuplicate(nums));
}

TEST(ContainsDuplicate, Example2AllDistinct) {
    dv::lc::Solution s;
    std::vector<int> nums{1, 2, 3, 4};
    EXPECT_FALSE(s.containsDuplicate(nums));
}

TEST(ContainsDuplicate, Example3ManyDuplicates) {
    dv::lc::Solution s;
    std::vector<int> nums{1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    EXPECT_TRUE(s.containsDuplicate(nums));
}

TEST(ContainsDuplicate, SingleElement) {
    dv::lc::Solution s;
    std::vector<int> nums{7};
    EXPECT_FALSE(s.containsDuplicate(nums));
}

TEST(ContainsDuplicate, ExtremeValuesDistinct) {
    dv::lc::Solution s;
    std::vector<int> nums{-1000000000, 1000000000, 0};
    EXPECT_FALSE(s.containsDuplicate(nums));
}

TEST(ContainsDuplicate, NegativeDuplicate) {
    dv::lc::Solution s;
    std::vector<int> nums{-1000000000, 5, -1000000000};
    EXPECT_TRUE(s.containsDuplicate(nums));
}

TEST(ContainsDuplicate, DuplicateAtEnds) {
    dv::lc::Solution s;
    std::vector<int> nums{2, 3, 4, 5, 2};
    EXPECT_TRUE(s.containsDuplicate(nums));
}
