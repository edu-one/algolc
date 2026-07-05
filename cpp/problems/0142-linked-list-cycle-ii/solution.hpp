/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */

#ifndef DV_LC_0142_LINKED_LIST_CYCLE_II_HPP
#define DV_LC_0142_LINKED_LIST_CYCLE_II_HPP

#include <dv/lc.hpp>

namespace dv::lc {

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        auto slow = head;
        auto fast = head;
        ListNode *meet_point = nullptr;
        while (slow && fast) {
            slow = slow->next;
            fast = (fast->next) ? fast->next->next : nullptr;
            if (slow == fast) {
                meet_point = head;
                break;
            }
        }
        while (meet_point && slow) {
            if (meet_point == slow)
                return meet_point;
            meet_point = meet_point->next;
            slow = slow->next;
        }
        return nullptr;
    }
};

} // namespace dv::lc

#endif // DV_LC_0142_LINKED_LIST_CYCLE_II_HPP
