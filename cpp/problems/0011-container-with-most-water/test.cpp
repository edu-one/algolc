/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */

#include "solution.hpp"

#include <gtest/gtest.h>

TEST(ContainerWithMostWater, Example1) {
    dv::lc::Solution s;
    EXPECT_EQ(49, s.maxArea({1, 8, 6, 2, 5, 4, 8, 3, 7}));
}

TEST(ContainerWithMostWater, Example2) {
    dv::lc::Solution s;
    EXPECT_EQ(1, s.maxArea({1, 1}));
}

TEST(ContainerWithMostWater, MinimalSize) {
    dv::lc::Solution s;
    EXPECT_EQ(0, s.maxArea({0, 0}));
}

TEST(ContainerWithMostWater, AllSameHeight) {
    dv::lc::Solution s;
    EXPECT_EQ(15, s.maxArea({5, 5, 5, 5}));
}

TEST(ContainerWithMostWater, StrictlyDescending) {
    dv::lc::Solution s;
    EXPECT_EQ(9, s.maxArea({6, 5, 4, 3, 2, 1}));
}

TEST(ContainerWithMostWater, StrictlyAscending) {
    dv::lc::Solution s;
    EXPECT_EQ(9, s.maxArea({1, 2, 3, 4, 5, 6}));
}

TEST(ContainerWithMostWater, TallOutliersAtEnds) {
    dv::lc::Solution s;
    EXPECT_EQ(40000, s.maxArea({10000, 1, 1, 1, 10000}));
}
