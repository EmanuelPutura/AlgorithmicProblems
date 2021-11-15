//
// Created by Emanuel on 15.11.2021.
//

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;

        string result = "";
        for (int r = 0; r < numRows && r < s.length(); ++r) {
            int i = r;
            result.push_back(s[r]);

            while (i < s.length()) {
                int first = 2 * numRows - 2 - 2 * r;
                int second = 2 * numRows - 2;

                if (i + first < s.length() && first > 0)
                    result.push_back(s[i + first]);
                if (first != second && i + second < s.length() && second > 0)
                    result.push_back(s[i + second]);

                if (!second)
                    break;
                i += second;
                // cout << first << ' ' << second << ' ' << result << '\n';
            }
        }

        return result;
    }
};