# Copyright (C) Denys Valchuk - All Rights Reserved
# ZHZhbGNodWtAZ21haWwuY29tCg==

from __future__ import annotations


class ListNode:
    def __init__(self, val: int = 0, next: ListNode | None = None):
        self.val = val
        self.next = next


class Solution:
    def mergeTwoLists(
        self, list1: ListNode | None, list2: ListNode | None
    ) -> ListNode | None:
        dummy = ListNode()
        rit = dummy
        while list1 and list2:
            if list1.val < list2.val:
                rit.next = list1
                list1 = list1.next
            else:
                rit.next = list2
                list2 = list2.next
            rit = rit.next
        rit.next = list1 or list2
        return dummy.next
