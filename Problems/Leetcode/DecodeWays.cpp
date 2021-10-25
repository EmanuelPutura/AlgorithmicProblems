//
// Created by Emanuel on 25.10.2021.
//

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        std::vector<int> res (s.length(), 0);  // res[i] - number of ways to decode s[0..i]
        int prev1 = 1, prev2 = 1, current = 1;

        if (s[0] == '0')
            return 0;

        for (int i = 1; i < s.length(); ++i) {
            if ((s[i] >= '0' && s[i] <= '6' && s[i - 1] == '2') || (s[i - 1] == '1' && s[i] >= '0' && s[i] <= '9')) {
                if (s[i] != '0')
                    current = prev1 + prev2;
                else
                    current = prev2;
                prev2 = prev1;
                prev1 = current;
            }
            else if (s[i] == '0')
                return 0;
            else {
                prev2 = prev1;
                prev1 = current;
            }
        }

        return current;
    }
};