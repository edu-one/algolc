/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */

pub struct Solution;

impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut profit: i32 = 0;
        let mut min = i32::MAX;
        for p in &prices {
            if *p < min {
                min = *p;
                continue;
            }
            let diff = *p - min;
            profit = std::cmp::max(profit, diff);
        }
        profit
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_example1() {
        assert_eq!(Solution::max_profit(vec![7, 1, 5, 3, 6, 4]), 5);
    }

    #[test]
    fn test_example2() {
        assert_eq!(Solution::max_profit(vec![7, 6, 4, 3, 1]), 0);
    }

    #[test]
    fn test_single_day() {
        assert_eq!(Solution::max_profit(vec![5]), 0);
    }

    #[test]
    fn test_two_days_profit() {
        assert_eq!(Solution::max_profit(vec![1, 2]), 1);
    }

    #[test]
    fn test_two_days_loss() {
        assert_eq!(Solution::max_profit(vec![2, 1]), 0);
    }

    #[test]
    fn test_minimum_at_end() {
        assert_eq!(Solution::max_profit(vec![2, 4, 1]), 2);
    }

    #[test]
    fn test_all_same_price() {
        assert_eq!(Solution::max_profit(vec![3, 3, 3, 3]), 0);
    }
}
