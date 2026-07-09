/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */

#include "solution.hpp"

#include <gtest/gtest.h>

#include <string>
#include <vector>

TEST(EncodeAndDecodeStrings, Example1) {
    dv::lc::Solution s;
    std::vector<std::string> strs{"Hello", "World"};
    EXPECT_EQ(strs, s.decode(s.encode(strs)));
}

TEST(EncodeAndDecodeStrings, SingleEmptyString) {
    dv::lc::Solution s;
    std::vector<std::string> strs{""};
    EXPECT_EQ(strs, s.decode(s.encode(strs)));
}

TEST(EncodeAndDecodeStrings, EmptyList) {
    dv::lc::Solution s;
    std::vector<std::string> strs{};
    EXPECT_EQ(strs, s.decode(s.encode(strs)));
}

TEST(EncodeAndDecodeStrings, DelimiterLikeCharacters) {
    dv::lc::Solution s;
    std::vector<std::string> strs{"4", "two#three", "", "abc:def"};
    EXPECT_EQ(strs, s.decode(s.encode(strs)));
}

TEST(EncodeAndDecodeStrings, ManyEmptyStrings) {
    dv::lc::Solution s;
    std::vector<std::string> strs{"", "", ""};
    EXPECT_EQ(strs, s.decode(s.encode(strs)));
}

TEST(EncodeAndDecodeStrings, SingleNonEmptyString) {
    dv::lc::Solution s;
    std::vector<std::string> strs{"leetcode"};
    EXPECT_EQ(strs, s.decode(s.encode(strs)));
}
