/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */

pub struct Solution;

impl Solution {
    pub fn longest_common_prefix(strs: Vec<String>) -> String {
        // TODO: solve 0014 - longest-common-prefix
        let _ = strs;
        String::new()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    #[ignore = "implement solution first"]
    fn placeholder() {
        let result = Solution::longest_common_prefix(
            vec!["flower".to_string(), "flow".to_string(), "flight".to_string()]
        );
        assert_eq!(result, "fl");
    }
}
