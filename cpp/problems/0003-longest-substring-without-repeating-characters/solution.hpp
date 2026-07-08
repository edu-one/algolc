/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */

#ifndef DV_LC_0003_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS_HPP
#define DV_LC_0003_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS_HPP

#include <algorithm>
#include <string>
#include <unordered_map>

namespace dv::lc {

using Seen = std::unordered_map<char, size_t>;

class Solution {
    void cleanPrefix(Seen &p, const std::string &s, size_t from, size_t to) const {
        for (size_t i = from; i <= to; ++i)
            p.erase(s[i]);
    }

public:
    int lengthOfLongestSubstring(const std::string &s) {
        if (s.size() < 2) {
            return s.size();
        }
        Seen seen;
        int maxLength = 0;
        size_t li = 0;
        size_t ri = 0;
        int length = 0;
        while (li <= ri && (s.size() - li - 1 >= maxLength) && ri < s.size()) {
            const char c = s[ri];
            const auto fit = seen.find(c);
            if (fit == seen.end()) {
                seen[c] = ri;
                ++ri;
                ++length;
                maxLength = std::max(maxLength, length);
                continue;
            }
            const auto seenAt = fit->second;
            cleanPrefix(seen, s, li, seenAt);
            length -= (seenAt - li);
            maxLength = std::max(maxLength, length);
            li = seenAt + 1;
            seen[c] = ri;
            ++ri;
        }
        return maxLength;
    }
};

} // namespace dv::lc

#endif // DV_LC_0003_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS_HPP
