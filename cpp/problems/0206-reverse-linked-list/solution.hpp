/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */

#ifndef DV_LC_0206_REVERSE_LINKED_LIST_HPP
#define DV_LC_0206_REVERSE_LINKED_LIST_HPP

#include <dv/lc.hpp>

namespace dv::lc {

class Solution {

    ListNode *visit(ListNode *prev, ListNode *node) {
        ListNode *head = nullptr;
        if (node->next) {
            head = visit(node, node->next);
        }
        node->next = prev;
        return head ? head : node;
    }

public:
    ListNode *reverseList(ListNode *head) {
        if (!head || !head->next)
            return head;
        auto newHead = visit(head, head->next);
        head->next = nullptr;
        return newHead;
    }
};

} // namespace dv::lc

#endif // DV_LC_0206_REVERSE_LINKED_LIST_HPP
