/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */

#ifndef DV_LC_0094_BINARY_TREE_INORDER_TRAVERSAL_HPP
#define DV_LC_0094_BINARY_TREE_INORDER_TRAVERSAL_HPP

#include <dv/lc.hpp>

#include <stack>
#include <vector>

namespace dv::lc {

class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode *root) {
        std::vector<int> result;
        TreeNode *node = root;
        std::stack<TreeNode *> path;
        while (node || !path.empty()) {
            while (node) {
                path.push(node);
                node = node->left;
            }

            node = path.top();
            path.pop();
            result.push_back(node->val);

            node = node->right;
        }
        return result;
    }
};

} // namespace dv::lc

#endif // DV_LC_0094_BINARY_TREE_INORDER_TRAVERSAL_HPP
