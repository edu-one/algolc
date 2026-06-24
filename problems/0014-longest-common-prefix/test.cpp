/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */

#include "solution.hpp"

#include <gtest/gtest.h>
#include <string>
#include <vector>

namespace {

using dv::lc::Solution;

TEST(LongestCommonPrefix, Example1_FlowerFlowFlight) {
    EXPECT_EQ(Solution{}.longestCommonPrefix({"flower", "flow", "flight"}), "fl");
}

TEST(LongestCommonPrefix, Example2_NoCommonPrefix) {
    EXPECT_EQ(Solution{}.longestCommonPrefix({"dog", "racecar", "car"}), "");
}

// Edge: single string — the whole string is the prefix
TEST(LongestCommonPrefix, SingleString) {
    EXPECT_EQ(Solution{}.longestCommonPrefix({"alone"}), "alone");
}

// Edge: all strings are identical
TEST(LongestCommonPrefix, AllIdentical) {
    EXPECT_EQ(Solution{}.longestCommonPrefix({"abc", "abc", "abc"}), "abc");
}

// Edge: one empty string in the array — prefix must be ""
TEST(LongestCommonPrefix, EmptyStringInArray) {
    EXPECT_EQ(Solution{}.longestCommonPrefix({"abc", "", "ab"}), "");
}

// Edge: all strings are empty
TEST(LongestCommonPrefix, AllEmpty) {
    EXPECT_EQ(Solution{}.longestCommonPrefix({"", "", ""}), "");
}

// Edge: prefix is a single character
TEST(LongestCommonPrefix, SingleCharPrefix) {
    EXPECT_EQ(Solution{}.longestCommonPrefix({"abc", "axy", "az"}), "a");
}

// Edge: full prefix match on the shortest string
TEST(LongestCommonPrefix, PrefixEqualsShortestString) {
    EXPECT_EQ(Solution{}.longestCommonPrefix({"ab", "abc", "abcd"}), "ab");
}

// Edge: max-length strings with a common prefix of 1
TEST(LongestCommonPrefix, LongStringsOneTruncation) {
    std::string base(200, 'a');
    std::string diff = "a" + std::string(199, 'b');
    EXPECT_EQ(Solution{}.longestCommonPrefix({base, diff}), "a");
}

} // namespace
