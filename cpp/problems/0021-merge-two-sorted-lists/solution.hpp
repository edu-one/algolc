/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */

#ifndef DV_LC_0021_MERGE_TWO_SORTED_LISTS_HPP
#define DV_LC_0021_MERGE_TWO_SORTED_LISTS_HPP

#include <dv/lc.hpp>

namespace dv::lc {

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode head;
        ListNode *tail = &head;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = (l1 != nullptr) ? l1 : l2;
        return head.next;
    }
};

} // namespace dv::lc

#endif // DV_LC_0021_MERGE_TWO_SORTED_LISTS_HPP
