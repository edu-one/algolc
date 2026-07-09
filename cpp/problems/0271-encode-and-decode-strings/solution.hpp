/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */

#ifndef DV_LC_0271_ENCODE_AND_DECODE_STRINGS_HPP
#define DV_LC_0271_ENCODE_AND_DECODE_STRINGS_HPP

#include <format>
#include <string>
#include <vector>

namespace dv::lc {

class Solution {
public:
    std::string encode(const std::vector<std::string> &strs) {
        std::string result = std::format("{:03}", strs.size());
        for (const auto &s : strs) {
            result += std::format("{:03}", s.size());
            result += s;
        }
        return result;
    }

    std::vector<std::string> decode(const std::string &s) {
        std::vector<std::string> result;
        const std::string szstr = s.substr(0, 3);
        const size_t sz = std::stoul(szstr);
        size_t offset = 3;
        for (size_t i = 0; i < sz; ++i) {
            const std::string sszstr = s.substr(offset, 3);
            const size_t ssz = std::stoul(sszstr);
            offset += 3;
            if (ssz) {
                const std::string ss = s.substr(offset, ssz);
                result.push_back(ss);
                offset += ssz;
            } else {
                result.push_back({});
            }
        }
        return result;
    }
};

} // namespace dv::lc

#endif // DV_LC_0271_ENCODE_AND_DECODE_STRINGS_HPP
