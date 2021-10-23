//
// Created by Emanuel on 23.10.2021.
//

#include <vector>
using namespace std;

class Solution {
public:
    bool validIndices(const vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
            return false;
        if (grid[i][j] == 0)
            return false;
        return true;
    }

    int traverseAndComputeGold(vector<vector<int>>& grid, int i, int j) {
        if (!validIndices(grid, i, j))
            return 0;

        int gold = grid[i][j];
        grid[i][j] = 0;

        int result = gold;
        int up = traverseAndComputeGold(grid, i - 1, j);
        int down = traverseAndComputeGold(grid, i + 1, j);
        int right = traverseAndComputeGold(grid, i, j + 1);
        int left = traverseAndComputeGold(grid, i, j - 1);

        result += std::max({up, down, right, left});
        grid[i][j] = gold;
        return result;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int result = 0;
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
                result = std::max(result, traverseAndComputeGold(grid, i, j));
        return result;
    }
};