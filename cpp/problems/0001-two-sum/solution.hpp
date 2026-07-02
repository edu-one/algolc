/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */

#ifndef DV_LC_0001_TWO_SUM_HPP
#define DV_LC_0001_TWO_SUM_HPP

#include <unordered_map>
#include <vector>

namespace dv::lc {

class Solution {
public:
    std::vector<int> twoSum(const std::vector<int> &nums, int target) {
        std::unordered_map<int, int> seen;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            auto it = seen.find(target - nums[i]);
            if (it != seen.end())
                return {it->second, i};
            seen[nums[i]] = i;
        }
        return {};
    }
};

} // namespace dv::lc

#endif // DV_LC_0001_TWO_SUM_HPP
