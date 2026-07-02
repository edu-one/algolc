/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */

#ifndef DV_INCLUDE_LC_HPP
#define DV_INCLUDE_LC_HPP

namespace dv::lc {

// Singly-linked list node used by many list problems.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val{0}, next{nullptr} {}
    explicit ListNode(int x) : val{x}, next{nullptr} {}
    ListNode(int x, ListNode *next) : val{x}, next{next} {}
};

// Binary tree node used by many tree problems.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val{0}, left{nullptr}, right{nullptr} {}
    explicit TreeNode(int x) : val{x}, left{nullptr}, right{nullptr} {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val{x}, left{left}, right{right} {}
};

} // namespace dv::lc

#endif // DV_INCLUDE_LC_HPP
