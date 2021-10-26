//
// Created by Emanuel on 26.10.2021.
//

#include <vector>

class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> possibilities (n);
        for (int i = 0; i < possibilities.size(); ++i)
            possibilities[i] = std::vector<int> (m, 0);

        for (int i = 0; i < n; ++i)
            possibilities[i][0] = 1;

        for (int j = 0; j < m; ++j)
            possibilities[0][j] = 1;

        for (int i = 1; i < n; ++i)
            for (int j = 1; j < m; ++j)
                possibilities[i][j] = possibilities[i - 1][j] + possibilities[i][j - 1];

        return possibilities[n - 1][m - 1];
    }
};