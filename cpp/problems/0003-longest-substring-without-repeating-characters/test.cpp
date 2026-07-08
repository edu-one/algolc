/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */

#include "solution.hpp"

#include <gtest/gtest.h>

TEST(LongestSubstringWithoutRepeatingCharacters, Example1) {
    dv::lc::Solution s;
    EXPECT_EQ(3, s.lengthOfLongestSubstring("abcabcbb"));
}

TEST(LongestSubstringWithoutRepeatingCharacters, Example2) {
    dv::lc::Solution s;
    EXPECT_EQ(1, s.lengthOfLongestSubstring("bbbbb"));
}

TEST(LongestSubstringWithoutRepeatingCharacters, Example3) {
    dv::lc::Solution s;
    EXPECT_EQ(3, s.lengthOfLongestSubstring("pwwkew"));
}

TEST(LongestSubstringWithoutRepeatingCharacters, EmptyString) {
    dv::lc::Solution s;
    EXPECT_EQ(0, s.lengthOfLongestSubstring(""));
}

TEST(LongestSubstringWithoutRepeatingCharacters, SingleCharacter) {
    dv::lc::Solution s;
    EXPECT_EQ(1, s.lengthOfLongestSubstring("a"));
}

TEST(LongestSubstringWithoutRepeatingCharacters, AllUnique) {
    dv::lc::Solution s;
    EXPECT_EQ(6, s.lengthOfLongestSubstring("abcdef"));
}

TEST(LongestSubstringWithoutRepeatingCharacters, RepeatAtEnd) {
    dv::lc::Solution s;
    EXPECT_EQ(5, s.lengthOfLongestSubstring("abcdea"));
}

TEST(LongestSubstringWithoutRepeatingCharacters, WithSpacesAndSymbols) {
    dv::lc::Solution s;
    EXPECT_EQ(4, s.lengthOfLongestSubstring("a b!a"));
}
