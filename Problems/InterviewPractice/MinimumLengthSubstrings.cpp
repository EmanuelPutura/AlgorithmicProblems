//
// Created by Emanuel on 07.11.2021.
//

#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here

int minLengthSubstring(string s, string t) {
    std::unordered_map<char, int> tchars;
    int t_letters = 0;

    for (int i = 0; i < t.length(); ++i) {
        if (!tchars[t[i]])
            t_letters++;
        tchars[t[i]]++;
    }

    int ok_tletters = 0, current_st = 0;
    int min = 0x3f3f3f3f;
    std::unordered_map<char, int> substr_tchars;

    for (int i = 0; i < s.length(); ++i) {
        if (tchars[s[i]]) {
            substr_tchars[s[i]]++;

            if (substr_tchars[s[i]] == tchars[s[i]])
                ok_tletters++;
            if (ok_tletters == t_letters) {
                for (int j = current_st; j <= i; ++j) {
                    if (!tchars[s[j]])
                        continue;
                    else {
                        if (substr_tchars[s[j]] > tchars[s[j]]) {
                            substr_tchars[s[j]]--;
                            continue;
                        }
                        else break;
                    }
                    current_st++;
                }

                int len = i - current_st + 1;
                if (len < min)
                    min = len;
            }
        }
    }

    return min != 0x3f3f3f3f ? min : -1;
}