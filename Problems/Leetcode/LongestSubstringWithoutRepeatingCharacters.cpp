//
// Created by Emanuel on 30.09.2021.
//

#include <string>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
    std::unordered_map<char, int> chars;
    if (!s.size()) return 0;
    chars[s[0]] = 0;

    int max = 1, len = 1, start = 0;
    for (int i = 1; i < s.size(); ++i) {
        if (chars.find(s[i]) != chars.end()) {
            if (chars[s[i]] >= start) {
                start = chars[s[i]] + 1;
                len = i - chars[s[i]] - 1;
            }

        }

        chars[s[i]] = i;
        len++;

        if (len > max)
            max = len;

    }

    return max;
}
