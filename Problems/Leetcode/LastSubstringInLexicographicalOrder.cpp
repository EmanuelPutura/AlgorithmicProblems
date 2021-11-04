//
// Created by Emanuel on 04.11.2021.
//

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string lastSubstring(string str) {
        int l = 0, r = 1, len = 0;

        while (r + len < str.length()) {
            if (str[l + len] == str[r + len])
                len++;
            else if (str[l + len] < str[r + len]) {
                l = max(r, l + len + 1);
                r = l + 1;
                len = 0;
            }
            else {
                r = r + len + 1;
                len = 0;
            }
        }

        return str.substr(l);
    }
};
