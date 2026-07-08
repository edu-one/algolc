/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */

#include "solution.hpp"

#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

namespace {

// Output order is unspecified: sort before comparing.
std::vector<int> topKFrequent(const std::vector<int> &nums, int k) {
    dv::lc::Solution solution;
    auto result = solution.topKFrequent(nums, k);
    std::sort(result.begin(), result.end());
    return result;
}

} // namespace

TEST(TopKFrequentElements, Example1MixedFrequencies) {
    const std::vector<int> expected = {1, 2};
    EXPECT_EQ(topKFrequent({1, 1, 1, 2, 2, 3}, 2), expected);
}

TEST(TopKFrequentElements, Example2SingleElement) {
    const std::vector<int> expected = {1};
    EXPECT_EQ(topKFrequent({1}, 1), expected);
}

TEST(TopKFrequentElements, Example3TiedFrequencies) {
    const std::vector<int> expected = {1, 2};
    EXPECT_EQ(topKFrequent({1, 2, 1, 2, 1, 2, 3, 1, 3, 2}, 2), expected);
}

TEST(TopKFrequentElements, KEqualsUniqueCountReturnsAll) {
    std::vector<int> expected = {1, 2, 3};
    std::sort(expected.begin(), expected.end());
    EXPECT_EQ(topKFrequent({1, 2, 3}, 3), expected);
}

TEST(TopKFrequentElements, NegativeNumbers) {
    const std::vector<int> expected = {-1, 5};
    EXPECT_EQ(topKFrequent({-1, -1, -1, 5, 5, 2}, 2), expected);
}

TEST(TopKFrequentElements, AllSameElement) {
    const std::vector<int> expected = {7};
    EXPECT_EQ(topKFrequent({7, 7, 7, 7}, 1), expected);
}

TEST(TopKFrequentElements, KEqualsOnePicksMostFrequent) {
    const std::vector<int> expected = {4};
    EXPECT_EQ(topKFrequent({1, 2, 4, 4, 4, 3, 3}, 1), expected);
}
