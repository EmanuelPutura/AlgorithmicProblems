//
// Created by Emanuel on 25.10.2021.
//

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        // min_steps[i][j] = min number of steps to make s[i..j] palindrome
        std::vector<std::vector<int>> min_steps (s.size());
        for (int i = 0; i < min_steps.size(); ++i)
            min_steps[i] = std::vector<int> (s.size(), 0);

        int current_col = 1;
        while (current_col < s.size()) {
            int i = 0, j = current_col;
            while (i < s.size() && j < s.size()) {
                if (s[i] == s[j])
                    min_steps[i][j] = min_steps[i + 1][j - 1];
                else {
                    if (min_steps[i + 1][j] < min_steps[i][j - 1])
                        min_steps[i][j] = min_steps[i + 1][j] + 1;
                    else min_steps[i][j] = min_steps[i][j - 1] + 1;
                }

                i++;
                j++;
            }
            current_col++;
        }

        return min_steps[0][s.size() - 1];
    }
};