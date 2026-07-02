/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */

#ifndef DV_LC_0014_LONGEST_COMMON_PREFIX_HPP
#define DV_LC_0014_LONGEST_COMMON_PREFIX_HPP

#include <string>
#include <vector>

namespace dv::lc {

using Strings = std::vector<std::string>;

class Solution {
public:
    std::string longestCommonPrefix(const Strings &in) {
        std::string result = in[0];
        for (size_t i = 1; i < in.size(); ++i) {
            size_t idx = 0;
            const auto &s = in[i];
            while (idx < s.size() && idx < result.size() && result[idx] == s[idx]) {
                ++idx;
            }
            result.resize(idx);
            if (result.empty())
                break;
        }
        return result;
    }
};

} // namespace dv::lc

#endif // DV_LC_0014_LONGEST_COMMON_PREFIX_HPP
