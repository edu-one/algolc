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

TEST(ReverseLinkedList, Example1) {
    dv::lc::Solution s;
    dv::lc::ListNode *reversed = s.reverseList(make_list({1, 2, 3, 4, 5}));
    EXPECT_EQ((std::vector<int>{5, 4, 3, 2, 1}), to_vector(reversed));
    free_list(reversed);
}

TEST(ReverseLinkedList, Example2) {
    dv::lc::Solution s;
    dv::lc::ListNode *reversed = s.reverseList(make_list({1, 2}));
    EXPECT_EQ((std::vector<int>{2, 1}), to_vector(reversed));
    free_list(reversed);
}

TEST(ReverseLinkedList, EmptyList) {
    dv::lc::Solution s;
    EXPECT_EQ(nullptr, s.reverseList(nullptr));
}

TEST(ReverseLinkedList, SingleNode) {
    dv::lc::Solution s;
    dv::lc::ListNode *reversed = s.reverseList(make_list({42}));
    EXPECT_EQ((std::vector<int>{42}), to_vector(reversed));
    free_list(reversed);
}
