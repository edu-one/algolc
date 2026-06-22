/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */

#ifndef __DV_INCLUDE_LC_HPP__
#define __DV_INCLUDE_LC_HPP__

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

#endif // __DV_INCLUDE_LC_HPP__
