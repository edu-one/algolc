/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */

#[derive(Debug, PartialEq, Eq)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    fn new(val: i32) -> Self {
        ListNode { val, next: None }
    }
}

pub struct Solution;

impl Solution {
    pub fn merge_two_lists(
        mut list1: Option<Box<ListNode>>,
        mut list2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        let mut dummy = Box::new(ListNode::new(0));
        let mut rit: &mut Option<Box<ListNode>> = &mut dummy.next;
        while let (Some(l1), Some(l2)) = (&list1, &list2) {
            if l1.val < l2.val {
                let mut node = list1.take().unwrap();
                list1 = node.next.take();
                *rit = Some(node);
                rit = &mut rit.as_mut().unwrap().next;
            } else {
                let mut node = list2.take().unwrap();
                list2 = node.next.take();
                *rit = Some(node);
                rit = &mut rit.as_mut().unwrap().next;
            }
        }
        *rit = list1.or(list2);
        dummy.next
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn to_list(vals: &[i32]) -> Option<Box<ListNode>> {
        vals.iter().rev().fold(None, |next, &val| {
            Some(Box::new(ListNode { val, next }))
        })
    }

    fn to_vec(mut node: Option<Box<ListNode>>) -> Vec<i32> {
        let mut result = Vec::new();
        while let Some(n) = node {
            result.push(n.val);
            node = n.next;
        }
        result
    }

    #[test]
    fn test_example1() {
        let result = Solution::merge_two_lists(to_list(&[1, 2, 4]), to_list(&[1, 3, 4]));
        assert_eq!(to_vec(result), vec![1, 1, 2, 3, 4, 4]);
    }

    #[test]
    fn test_example2_both_empty() {
        assert_eq!(Solution::merge_two_lists(None, None), None);
    }

    #[test]
    fn test_example3_one_empty() {
        let result = Solution::merge_two_lists(None, to_list(&[0]));
        assert_eq!(to_vec(result), vec![0]);
    }

    #[test]
    fn test_first_list_empty() {
        let result = Solution::merge_two_lists(to_list(&[1, 3, 5]), None);
        assert_eq!(to_vec(result), vec![1, 3, 5]);
    }

    #[test]
    fn test_single_elements() {
        let result = Solution::merge_two_lists(to_list(&[2]), to_list(&[1]));
        assert_eq!(to_vec(result), vec![1, 2]);
    }

    #[test]
    fn test_all_same() {
        let result = Solution::merge_two_lists(to_list(&[1, 1]), to_list(&[1, 1]));
        assert_eq!(to_vec(result), vec![1, 1, 1, 1]);
    }
}
