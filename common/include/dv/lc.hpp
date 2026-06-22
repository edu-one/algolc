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
        ListNode() : val(0), next(nullptr) {}
        explicit ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

} // namespace dv::lc

#endif // DV_INCLUDE_LC_HPP
