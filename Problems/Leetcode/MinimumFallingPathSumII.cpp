//
// Created by Emanuel on 03.11.2021.
//

#include <vector>
using namespace std;

class Solution {
private:
    const int INF = 0x3f3f3f3f;
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 1)
            return grid[0][0];

        int min1 = 0, min2 = 0;
        int ind1 = -1, ind2 = 11;

        for (int i = 0; i < n; ++i) {
            int cmin1 = INF, cmin2 = INF;
            int cind1 = -1, cind2 = -1;

            for (int j = 0; j < n; ++j) {
                int crt;
                if (j != ind1)
                    crt = min1 + grid[i][j];
                else crt = min2 + grid[i][j];

                if (crt < cmin1) {
                    cmin2 = cmin1;
                    cmin1 = crt;
                    cind2 = cind1;
                    cind1 = j;
                }
                else if (crt < cmin2) {
                    cmin2 = crt;
                    cind2 = j;
                }
            }

            min1 = cmin1; min2 = cmin2; ind1 = cind1; ind2 = cind2;
        }

        return min1;
    }
};