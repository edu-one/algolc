/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */

#include "solution.hpp"

#include <gtest/gtest.h>

namespace {

bool isAnagram(std::string s, std::string t) {
    dv::lc::Solution solution;
    return solution.isAnagram(std::move(s), std::move(t));
}

} // namespace

TEST(ValidAnagram, Example1Anagram) { EXPECT_TRUE(isAnagram("anagram", "nagaram")); }

TEST(ValidAnagram, Example2NotAnagram) { EXPECT_FALSE(isAnagram("rat", "car")); }

TEST(ValidAnagram, DifferentLengths) { EXPECT_FALSE(isAnagram("ab", "a")); }

TEST(ValidAnagram, SingleCharEqual) { EXPECT_TRUE(isAnagram("a", "a")); }

TEST(ValidAnagram, SingleCharDifferent) { EXPECT_FALSE(isAnagram("a", "b")); }

TEST(ValidAnagram, IdenticalStrings) { EXPECT_TRUE(isAnagram("listen", "listen")); }

TEST(ValidAnagram, SameLettersDifferentCounts) { EXPECT_FALSE(isAnagram("aacc", "ccac")); }

TEST(ValidAnagram, RepeatedSingleLetter) { EXPECT_TRUE(isAnagram("aaaa", "aaaa")); }
