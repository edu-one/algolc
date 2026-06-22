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

TEST(MergeTwoLists, Example1) {
    dv::lc::Solution s;
    dv::lc::ListNode *merged = s.mergeTwoLists(make_list({1, 2, 4}), make_list({1, 3, 4}));
    EXPECT_EQ((std::vector<int>{1, 1, 2, 3, 4, 4}), to_vector(merged));
    free_list(merged);
}

TEST(MergeTwoLists, BothEmpty) {
    dv::lc::Solution s;
    EXPECT_EQ(nullptr, s.mergeTwoLists(nullptr, nullptr));
}

TEST(MergeTwoLists, OneEmpty) {
    dv::lc::Solution s;
    dv::lc::ListNode *merged = s.mergeTwoLists(nullptr, make_list({0}));
    EXPECT_EQ((std::vector<int>{0}), to_vector(merged));
    free_list(merged);
}
