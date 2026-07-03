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
    assert to_list(s.reverseList(make_list([1, 2, 3, 4, 5]))) == [5, 4, 3, 2, 1]


def test_example2():
    assert to_list(s.reverseList(make_list([1, 2]))) == [2, 1]


def test_empty_list():
    assert to_list(s.reverseList(None)) == []


def test_single_node():
    assert to_list(s.reverseList(make_list([42]))) == [42]
