/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */

#include "solution.hpp"

#include <dv/lc.hpp>
#include <gtest/gtest.h>

#include <initializer_list>
#include <vector>

namespace {

// Builds a list from `values`, linking the tail's next to the node at `pos`
// (0-indexed) to create a cycle, or leaving it null if `pos` is -1.
// Returns the head; all allocated nodes are also appended to `nodes` so the
// caller can free them without traversing a possibly-cyclic list.
dv::lc::ListNode *make_list(std::initializer_list<int> values, int pos, std::vector<dv::lc::ListNode *> &nodes) {
    dv::lc::ListNode head;
    dv::lc::ListNode *tail = &head;
    for (int v : values) {
        tail->next = new dv::lc::ListNode(v);
        tail = tail->next;
        nodes.push_back(tail);
    }
    if (pos >= 0 && !nodes.empty())
        tail->next = nodes[static_cast<size_t>(pos)];
    return head.next;
}

void free_nodes(std::vector<dv::lc::ListNode *> &nodes) {
    for (dv::lc::ListNode *node : nodes)
        delete node;
}

} // namespace

TEST(LinkedListCycle, Example1CycleToMiddle) {
    dv::lc::Solution s;
    std::vector<dv::lc::ListNode *> nodes;
    dv::lc::ListNode *head = make_list({3, 2, 0, -4}, 1, nodes);
    EXPECT_TRUE(s.hasCycle(head));
    free_nodes(nodes);
}

TEST(LinkedListCycle, Example2CycleToHead) {
    dv::lc::Solution s;
    std::vector<dv::lc::ListNode *> nodes;
    dv::lc::ListNode *head = make_list({1, 2}, 0, nodes);
    EXPECT_TRUE(s.hasCycle(head));
    free_nodes(nodes);
}

TEST(LinkedListCycle, Example3NoCycle) {
    dv::lc::Solution s;
    std::vector<dv::lc::ListNode *> nodes;
    dv::lc::ListNode *head = make_list({1}, -1, nodes);
    EXPECT_FALSE(s.hasCycle(head));
    free_nodes(nodes);
}

TEST(LinkedListCycle, EmptyList) {
    dv::lc::Solution s;
    EXPECT_FALSE(s.hasCycle(nullptr));
}

TEST(LinkedListCycle, NoCycleMultipleNodes) {
    dv::lc::Solution s;
    std::vector<dv::lc::ListNode *> nodes;
    dv::lc::ListNode *head = make_list({1, 2, 3, 4, 5}, -1, nodes);
    EXPECT_FALSE(s.hasCycle(head));
    free_nodes(nodes);
}

TEST(LinkedListCycle, SelfLoop) {
    dv::lc::Solution s;
    std::vector<dv::lc::ListNode *> nodes;
    dv::lc::ListNode *head = make_list({1}, 0, nodes);
    EXPECT_TRUE(s.hasCycle(head));
    free_nodes(nodes);
}

TEST(LinkedListCycle, CycleAtTail) {
    dv::lc::Solution s;
    std::vector<dv::lc::ListNode *> nodes;
    dv::lc::ListNode *head = make_list({1, 2, 3, 4}, 3, nodes);
    EXPECT_TRUE(s.hasCycle(head));
    free_nodes(nodes);
}
