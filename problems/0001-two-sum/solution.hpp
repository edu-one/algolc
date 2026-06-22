/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */

#ifndef __DV_LC_0001_TWO_SUM_HPP__
#define __DV_LC_0001_TWO_SUM_HPP__

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

#endif // __DV_LC_0001_TWO_SUM_HPP__
