/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */

#ifndef DV_LC_0019_REMOVE_NTH_NODE_FROM_END_OF_LIST_HPP
#define DV_LC_0019_REMOVE_NTH_NODE_FROM_END_OF_LIST_HPP

#include <dv/lc.hpp>

namespace dv::lc {

class Solution {
    int target_ = 0;

    ListNode *removeImpl(ListNode *parent, ListNode *node, int n, int i) {
        if (node->next)
            removeImpl(node, node->next, n, i + 1);
        else {
            target_ = i + 1 - n;
        }
        if (i == target_) {
            auto toRemove = node;
            if (parent)
                parent->next = node->next;
            node = node->next;
            delete toRemove;
        }
        return node;
    }

public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (!head->next) {
            delete head;
            return nullptr;
        }
        head = removeImpl(nullptr, head, n, 0);
        return head;
    }
};

} // namespace dv::lc

#endif // DV_LC_0019_REMOVE_NTH_NODE_FROM_END_OF_LIST_HPP
