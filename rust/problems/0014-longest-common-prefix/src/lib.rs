/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */

pub struct Solution;

impl Solution {
    pub fn longest_common_prefix(strs: Vec<String>) -> String {
        if strs.is_empty() {
            return String::new();
        }
        let mut result = strs[0].clone();
        for s in &strs[1..] {
            let common_len = result
                .bytes()
                .zip(s.bytes())
                .take_while(|(a, b)| a == b)
                .count();
            result.truncate(common_len);
            if result.is_empty() {
                break;
            }
        }
        result
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn lcp(strs: &[&str]) -> String {
        Solution::longest_common_prefix(strs.iter().map(|s| s.to_string()).collect())
    }

    #[test]
    fn example1_flower_flow_flight() {
        assert_eq!(lcp(&["flower", "flow", "flight"]), "fl");
    }

    #[test]
    fn example2_no_common_prefix() {
        assert_eq!(lcp(&["dog", "racecar", "car"]), "");
    }

    #[test]
    fn single_string() {
        assert_eq!(lcp(&["alone"]), "alone");
    }

    #[test]
    fn all_identical() {
        assert_eq!(lcp(&["abc", "abc", "abc"]), "abc");
    }

    #[test]
    fn empty_string_in_array() {
        assert_eq!(lcp(&["abc", "", "ab"]), "");
    }

    #[test]
    fn all_empty() {
        assert_eq!(lcp(&["", "", ""]), "");
    }

    #[test]
    fn single_char_prefix() {
        assert_eq!(lcp(&["abc", "axy", "az"]), "a");
    }

    #[test]
    fn prefix_equals_shortest_string() {
        assert_eq!(lcp(&["ab", "abc", "abcd"]), "ab");
    }

    #[test]
    fn long_strings_one_truncation() {
        let base = "a".repeat(200);
        let diff = "a".to_string() + &"b".repeat(199);
        assert_eq!(lcp(&[&base, &diff]), "a");
    }
}
