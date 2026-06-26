/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */

#include "solution.hpp"

#include <dv/lc.hpp>
#include <gtest/gtest.h>

#include <optional>
#include <queue>
#include <vector>

namespace {

    // Build a binary tree from a level-order array (nullopt = missing node).
    dv::lc::TreeNode *make_tree(std::vector<std::optional<int>> vals) {
        if (vals.empty() || !vals[0])
            return nullptr;

        auto *root = new dv::lc::TreeNode(*vals[0]);
        std::queue<dv::lc::TreeNode *> q;
        q.push(root);
        std::size_t i = 1;

        while (!q.empty() && i < vals.size()) {
            auto *node = q.front();
            q.pop();

            if (i < vals.size() && vals[i]) {
                node->left = new dv::lc::TreeNode(*vals[i]);
                q.push(node->left);
            }
            ++i;

            if (i < vals.size() && vals[i]) {
                node->right = new dv::lc::TreeNode(*vals[i]);
                q.push(node->right);
            }
            ++i;
        }

        return root;
    }

    void free_tree(dv::lc::TreeNode *node) {
        if (!node)
            return;
        free_tree(node->left);
        free_tree(node->right);
        delete node;
    }

} // namespace

// Examples from the problem statement

TEST(BinaryTreeInorderTraversal, Example1) {
    // [1,null,2,3] -> [1,3,2]
    auto *root = make_tree({1, std::nullopt, 2, 3});
    dv::lc::Solution s;
    EXPECT_EQ((std::vector<int>{1, 3, 2}), s.inorderTraversal(root));
    free_tree(root);
}

TEST(BinaryTreeInorderTraversal, Example2) {
    // [1,2,3,4,5,null,8,null,null,6,7,9] -> [4,2,6,5,7,1,3,9,8]
    auto *root = make_tree({1, 2, 3, 4, 5, std::nullopt, 8,
                            std::nullopt, std::nullopt, 6, 7, 9});
    dv::lc::Solution s;
    EXPECT_EQ((std::vector<int>{4, 2, 6, 5, 7, 1, 3, 9, 8}), s.inorderTraversal(root));
    free_tree(root);
}

TEST(BinaryTreeInorderTraversal, Example3_Empty) {
    dv::lc::Solution s;
    EXPECT_EQ((std::vector<int>{}), s.inorderTraversal(nullptr));
}

TEST(BinaryTreeInorderTraversal, Example4_SingleNode) {
    auto *root = make_tree({1});
    dv::lc::Solution s;
    EXPECT_EQ((std::vector<int>{1}), s.inorderTraversal(root));
    free_tree(root);
}

// Edge cases

TEST(BinaryTreeInorderTraversal, LeftSkewed) {
    // 3 -> 2 -> 1 (all left children) -> inorder [1,2,3]
    auto *root = make_tree({3, 2, std::nullopt, 1});
    dv::lc::Solution s;
    EXPECT_EQ((std::vector<int>{1, 2, 3}), s.inorderTraversal(root));
    free_tree(root);
}

TEST(BinaryTreeInorderTraversal, RightSkewed) {
    // 1 -> 2 -> 3 (all right children) -> inorder [1,2,3]
    auto *root = make_tree({1, std::nullopt, 2, std::nullopt, 3});
    dv::lc::Solution s;
    EXPECT_EQ((std::vector<int>{1, 2, 3}), s.inorderTraversal(root));
    free_tree(root);
}

TEST(BinaryTreeInorderTraversal, PerfectTree) {
    // Perfect binary tree: root=4, left=2, right=6, leaves=1,3,5,7
    auto *root = make_tree({4, 2, 6, 1, 3, 5, 7});
    dv::lc::Solution s;
    EXPECT_EQ((std::vector<int>{1, 2, 3, 4, 5, 6, 7}), s.inorderTraversal(root));
    free_tree(root);
}

TEST(BinaryTreeInorderTraversal, NegativeValues) {
    auto *root = make_tree({-1, -2, -3});
    dv::lc::Solution s;
    EXPECT_EQ((std::vector<int>{-2, -1, -3}), s.inorderTraversal(root));
    free_tree(root);
}
