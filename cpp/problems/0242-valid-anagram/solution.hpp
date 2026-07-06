/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */

#ifndef DV_LC_0242_VALID_ANAGRAM_HPP
#define DV_LC_0242_VALID_ANAGRAM_HPP

#include <array>
#include <string>

namespace dv::lc {

class Solution {

public:
    bool isAnagram(std::string s, std::string t) {
        std::array<int, 26> appearance{};
        if (s.size() != t.size())
            return false;
        for (size_t i = 0; i < s.size(); ++i) {
            const int sCPos = static_cast<int>(s[i]) - static_cast<int>('a');
            appearance[sCPos]++;
            const int tCPos = static_cast<int>(t[i]) - static_cast<int>('a');
            appearance[tCPos]--;
        }
        for (auto a : appearance) {
            if (a)
                return false;
        }
        return true;
    }
};

} // namespace dv::lc

#endif // DV_LC_0242_VALID_ANAGRAM_HPP
