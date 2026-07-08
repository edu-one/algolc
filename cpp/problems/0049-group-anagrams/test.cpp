/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */

#include "solution.hpp"

#include <gtest/gtest.h>

#include <algorithm>
#include <string>
#include <vector>

namespace {

using Groups = std::vector<std::vector<std::string>>;

// Output order is unspecified: sort strings within each group, then sort groups.
Groups normalized(Groups groups) {
    for (auto &group : groups)
        std::sort(group.begin(), group.end());
    std::sort(groups.begin(), groups.end());
    return groups;
}

Groups groupAnagrams(std::vector<std::string> strs) {
    dv::lc::Solution solution;
    return normalized(solution.groupAnagrams(strs));
}

} // namespace

TEST(GroupAnagrams, Example1MixedGroups) {
    const Groups expected = normalized({
        {"bat"},
        {"nat", "tan"},
        {"ate", "eat", "tea"}
    });
    EXPECT_EQ(groupAnagrams({"eat", "tea", "tan", "ate", "nat", "bat"}), expected);
}

TEST(GroupAnagrams, Example2SingleEmptyString) {
    const Groups expected = {{""}};
    EXPECT_EQ(groupAnagrams({""}), expected);
}

TEST(GroupAnagrams, Example3SingleChar) {
    const Groups expected = {{"a"}};
    EXPECT_EQ(groupAnagrams({"a"}), expected);
}

TEST(GroupAnagrams, NoAnagramsAllSingletons) {
    const Groups expected = normalized({{"a"}, {"b"}, {"c"}});
    EXPECT_EQ(groupAnagrams({"a", "b", "c"}), expected);
}

TEST(GroupAnagrams, AllOneGroup) {
    const Groups expected = normalized({
        {"abc", "bca", "cab", "cba"}
    });
    EXPECT_EQ(groupAnagrams({"abc", "bca", "cab", "cba"}), expected);
}

TEST(GroupAnagrams, DuplicateWordsStayTogether) {
    const Groups expected = normalized({
        {"eat", "eat", "tea"},
        {"tan"}
    });
    EXPECT_EQ(groupAnagrams({"eat", "tea", "eat", "tan"}), expected);
}

TEST(GroupAnagrams, MultipleEmptyStrings) {
    const Groups expected = normalized({
        {"", ""},
        {"a"}
    });
    EXPECT_EQ(groupAnagrams({"", "a", ""}), expected);
}

TEST(GroupAnagrams, SameLettersDifferentCounts) {
    const Groups expected = normalized({
        {"aab", "aba", "baa"},
        {"abb", "bab"}
    });
    EXPECT_EQ(groupAnagrams({"aab", "abb", "aba", "bab", "baa"}), expected);
}
