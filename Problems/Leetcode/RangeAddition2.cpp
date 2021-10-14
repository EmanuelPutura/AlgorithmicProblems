//
// Created by Emanuel on 14.10.2021.
//

#include <vector>

int maxCount(int m, int n, std::vector<std::vector<int>>& ops) {
    const int MAX = 40000;
    int minx = MAX, miny = MAX;

    for (const auto& op : ops) {
        int a = op[0], b = op[1];
        if (a < minx)
            minx = a;
        if (b < miny)
            miny = b;
    }

    if (ops.size())
        return minx * miny;
    return m * n;
}
