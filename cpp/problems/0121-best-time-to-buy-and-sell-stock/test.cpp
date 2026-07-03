/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */

#include "solution.hpp"

#include <gtest/gtest.h>

#include <vector>

TEST(BestTimeToBuyAndSellStock, Example1) {
    dv::lc::Solution s;
    EXPECT_EQ(5, s.maxProfit({7, 1, 5, 3, 6, 4}));
}

TEST(BestTimeToBuyAndSellStock, Example2) {
    dv::lc::Solution s;
    EXPECT_EQ(0, s.maxProfit({7, 6, 4, 3, 1}));
}

TEST(BestTimeToBuyAndSellStock, SingleDay) {
    dv::lc::Solution s;
    EXPECT_EQ(0, s.maxProfit({5}));
}

TEST(BestTimeToBuyAndSellStock, TwoDaysProfit) {
    dv::lc::Solution s;
    EXPECT_EQ(1, s.maxProfit({1, 2}));
}

TEST(BestTimeToBuyAndSellStock, TwoDaysLoss) {
    dv::lc::Solution s;
    EXPECT_EQ(0, s.maxProfit({2, 1}));
}

TEST(BestTimeToBuyAndSellStock, MinimumAtEnd) {
    dv::lc::Solution s;
    EXPECT_EQ(2, s.maxProfit({2, 4, 1}));
}

TEST(BestTimeToBuyAndSellStock, AllSamePrice) {
    dv::lc::Solution s;
    EXPECT_EQ(0, s.maxProfit({3, 3, 3, 3}));
}
