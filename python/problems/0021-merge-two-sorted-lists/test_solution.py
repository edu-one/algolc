# Copyright (C) Denys Valchuk - All Rights Reserved
# ZHZhbGNodWtAZ21haWwuY29tCg==

from solution import ListNode, Solution


def make_list(vals: list[int]) -> ListNode | None:
    dummy = ListNode()
    cur = dummy
    for v in vals:
        cur.next = ListNode(v)
        cur = cur.next
    return dummy.next


def to_list(node: ListNode | None) -> list[int]:
    result = []
    while node:
        result.append(node.val)
        node = node.next
    return result


s = Solution()


def test_example1():
    result = to_list(s.mergeTwoLists(make_list([1, 2, 4]), make_list([1, 3, 4])))
    assert result == [1, 1, 2, 3, 4, 4]


def test_example2_both_empty():
    assert to_list(s.mergeTwoLists(None, None)) == []


def test_example3_one_empty():
    assert to_list(s.mergeTwoLists(None, make_list([0]))) == [0]


def test_first_list_empty():
    assert to_list(s.mergeTwoLists(make_list([1, 3, 5]), None)) == [1, 3, 5]


def test_single_elements():
    assert to_list(s.mergeTwoLists(make_list([2]), make_list([1]))) == [1, 2]


def test_all_same():
    result = to_list(s.mergeTwoLists(make_list([1, 1]), make_list([1, 1])))
    assert result == [1, 1, 1, 1]
