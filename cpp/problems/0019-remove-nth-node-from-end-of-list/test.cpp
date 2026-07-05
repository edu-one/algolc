/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */

#include "solution.hpp"

#include <dv/lc.hpp>
#include <gtest/gtest.h>

#include <initializer_list>
#include <vector>

namespace {

dv::lc::ListNode *make_list(std::initializer_list<int> values) {
    dv::lc::ListNode head;
    dv::lc::ListNode *tail = &head;
    for (int v : values) {
        tail->next = new dv::lc::ListNode(v);
        tail = tail->next;
    }
    return head.next;
}

std::vector<int> to_vector(dv::lc::ListNode *node) {
    std::vector<int> out;
    for (; node != nullptr; node = node->next)
        out.push_back(node->val);
    return out;
}

void free_list(dv::lc::ListNode *node) {
    while (node != nullptr) {
        dv::lc::ListNode *next = node->next;
        delete node;
        node = next;
    }
}

} // namespace

TEST(RemoveNthNodeFromEndOfList, Example1) {
    dv::lc::Solution s;
    dv::lc::ListNode *result = s.removeNthFromEnd(make_list({1, 2, 3, 4, 5}), 2);
    EXPECT_EQ((std::vector<int>{1, 2, 3, 5}), to_vector(result));
    free_list(result);
}

TEST(RemoveNthNodeFromEndOfList, Example2SingleNode) {
    dv::lc::Solution s;
    dv::lc::ListNode *result = s.removeNthFromEnd(make_list({1}), 1);
    EXPECT_EQ(nullptr, result);
}

TEST(RemoveNthNodeFromEndOfList, Example3RemoveTail) {
    dv::lc::Solution s;
    dv::lc::ListNode *result = s.removeNthFromEnd(make_list({1, 2}), 1);
    EXPECT_EQ((std::vector<int>{1}), to_vector(result));
    free_list(result);
}

TEST(RemoveNthNodeFromEndOfList, RemoveHead) {
    dv::lc::Solution s;
    dv::lc::ListNode *result = s.removeNthFromEnd(make_list({1, 2, 3, 4, 5}), 5);
    EXPECT_EQ((std::vector<int>{2, 3, 4, 5}), to_vector(result));
    free_list(result);
}

TEST(RemoveNthNodeFromEndOfList, RemoveHeadOfPair) {
    dv::lc::Solution s;
    dv::lc::ListNode *result = s.removeNthFromEnd(make_list({1, 2}), 2);
    EXPECT_EQ((std::vector<int>{2}), to_vector(result));
    free_list(result);
}

TEST(RemoveNthNodeFromEndOfList, RemoveMiddle) {
    dv::lc::Solution s;
    dv::lc::ListNode *result = s.removeNthFromEnd(make_list({1, 2, 3}), 2);
    EXPECT_EQ((std::vector<int>{1, 3}), to_vector(result));
    free_list(result);
}
