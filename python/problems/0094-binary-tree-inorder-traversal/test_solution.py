# Copyright (C) Denys Valchuk - All Rights Reserved
# ZHZhbGNodWtAZ21haWwuY29tCg==

from solution import Solution, TreeNode


def make_tree(vals: list[int | None]) -> TreeNode | None:
    if not vals or vals[0] is None:
        return None

    root = TreeNode(vals[0])
    queue = [root]
    i = 1

    while queue and i < len(vals):
        node = queue.pop(0)

        if i < len(vals) and vals[i] is not None:
            node.left = TreeNode(vals[i])
            queue.append(node.left)
        i += 1

        if i < len(vals) and vals[i] is not None:
            node.right = TreeNode(vals[i])
            queue.append(node.right)
        i += 1

    return root


s = Solution()


# Examples from the problem statement


def test_example1():
    # [1,null,2,3] -> [1,3,2]
    root = make_tree([1, None, 2, 3])
    assert s.inorderTraversal(root) == [1, 3, 2]


def test_example2():
    # [1,2,3,4,5,null,8,null,null,6,7,9] -> [4,2,6,5,7,1,3,9,8]
    root = make_tree([1, 2, 3, 4, 5, None, 8, None, None, 6, 7, 9])
    assert s.inorderTraversal(root) == [4, 2, 6, 5, 7, 1, 3, 9, 8]


def test_example3_empty():
    assert s.inorderTraversal(None) == []


def test_example4_single_node():
    root = make_tree([1])
    assert s.inorderTraversal(root) == [1]


# Edge cases


def test_left_skewed():
    # 3 -> 2 -> 1 (all left children) -> inorder [1,2,3]
    root = make_tree([3, 2, None, 1])
    assert s.inorderTraversal(root) == [1, 2, 3]


def test_right_skewed():
    # 1 -> 2 -> 3 (all right children) -> inorder [1,2,3]
    root = make_tree([1, None, 2, None, 3])
    assert s.inorderTraversal(root) == [1, 2, 3]


def test_perfect_tree():
    # Perfect binary tree: root=4, left=2, right=6, leaves=1,3,5,7
    root = make_tree([4, 2, 6, 1, 3, 5, 7])
    assert s.inorderTraversal(root) == [1, 2, 3, 4, 5, 6, 7]


def test_negative_values():
    root = make_tree([-1, -2, -3])
    assert s.inorderTraversal(root) == [-2, -1, -3]
