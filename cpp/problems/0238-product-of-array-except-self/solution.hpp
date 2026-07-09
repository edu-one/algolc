/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */

#ifndef DV_LC_0238_PRODUCT_OF_ARRAY_EXCEPT_SELF_HPP
#define DV_LC_0238_PRODUCT_OF_ARRAY_EXCEPT_SELF_HPP

#include <vector>

namespace dv::lc {

class Solution {
public:
    std::vector<int> productExceptSelf(const std::vector<int> &nums) {
        std::vector<int> result(nums.size(), 1);
        // calc prefix
        for (size_t i = 1; i < nums.size(); ++i) {
            result[i] = result[i - 1] * nums[i - 1];
        }
        // calc suffixes
        int suffix = 1;
        for (int i = nums.size() - 2; i >= 0; --i) {
            suffix = suffix * nums[i + 1];
            result[i] = result[i] * suffix;
        }
        return result;
    }
};

} // namespace dv::lc

#endif // DV_LC_0238_PRODUCT_OF_ARRAY_EXCEPT_SELF_HPP
