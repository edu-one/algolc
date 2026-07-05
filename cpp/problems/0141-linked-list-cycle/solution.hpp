/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */

#ifndef DV_LC_0141_LINKED_LIST_CYCLE_HPP
#define DV_LC_0141_LINKED_LIST_CYCLE_HPP

#include <dv/lc.hpp>

namespace dv::lc {

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next)
            return false;
        ListNode *slow = head;
        ListNode *fast = head;
        while (slow && fast) {
            slow = slow->next;
            fast = (fast->next) ? fast->next->next : nullptr;
            if (fast && slow && fast == slow)
                return true;
        }
        return false;
    }
};

} // namespace dv::lc

#endif // DV_LC_0141_LINKED_LIST_CYCLE_HPP
