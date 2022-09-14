//
// Created by Emanuel on 14.09.2022.
//

#include <vector>

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size(), m = matrix.size() ? matrix[0].size() : 0;
        int init00 = matrix[0][0];

        bool vertical = false, horiz = false;

        if (!n || !m) {
            return;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!matrix[i][j]) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;

                    if (j == 0) {
                        vertical = true;
                    }
                    if (i == 0) {
                        horiz = true;
                    }
                }
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (!matrix[0][j] || !matrix[i][0]) {
                    if (i != 0 && j != 0) {
                        matrix[i][j] = 0;
                    }
                    else if (i == 0 && horiz) {
                        matrix[i][j] = 0;
                    }
                    else if (j == 0 && vertical) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }
    }
};
