/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */

#include "solution.hpp"

#include <gtest/gtest.h>

TEST(ValidParentheses, Example1) {
    dv::lc::Solution s;
    EXPECT_TRUE(s.isValid("()"));
}

TEST(ValidParentheses, Example2) {
    dv::lc::Solution s;
    EXPECT_TRUE(s.isValid("()[]{}"));
}

TEST(ValidParentheses, Example3) {
    dv::lc::Solution s;
    EXPECT_FALSE(s.isValid("(]"));
}

TEST(ValidParentheses, Example4) {
    dv::lc::Solution s;
    EXPECT_TRUE(s.isValid("([])"));
}

TEST(ValidParentheses, Example5) {
    dv::lc::Solution s;
    EXPECT_FALSE(s.isValid("([)]"));
}

TEST(ValidParentheses, SingleOpenBracket) {
    dv::lc::Solution s;
    EXPECT_FALSE(s.isValid("("));
}

TEST(ValidParentheses, SingleCloseBracket) {
    dv::lc::Solution s;
    EXPECT_FALSE(s.isValid(")"));
}

TEST(ValidParentheses, Nested) {
    dv::lc::Solution s;
    EXPECT_TRUE(s.isValid("{[()]}"));
}
