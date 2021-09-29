//
// Created by Emanuel on 28.09.2021.
//

#include <iostream>
#include <string>

using namespace std;

string longestPalindrome(string s) {
    int max = 1, max_c = 0;
    bool odd = true;
    for (int c = 0; c < s.size(); ++c) {
        int len = 1, i = c - 1, j = c + 1;
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            len += 2;
            i--;
            j++;
        }
        if (len > max) {
            max_c = c;
            odd = true;
            max = len;
        }

        i = c; j = c + 1; len = 0;
        while(i >= 0 && j < s.size() && s[i] == s[j]) {
            i--;
            j++;
            len += 2;
        }

        if (len > max) {
            odd = false;
            max_c = c;
            max = len;
        }
    }

    string result = "";

//    std::cout << max_c << ' ' << max << ' ' << odd << '\n';
    for (int i = max_c - max / 2 + 1 - odd; i <= max_c + max / 2; ++i) {
        result.push_back(s[i]);
    }


    return result;
}
