//
// Created by Emanuel on 30.03.2022.
//

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int computeProduct(int n, int k) {
        if (k < 2) {
            // then k has to be equal to two
            if (n % 2 == 0)
                return pow(n / 2, 2);
            else return n / 2 * (n / 2 + 1);
        }

        int minNo = n / k, maxCnt = n - minNo * k;
        return pow(minNo + 1, maxCnt) * pow(minNo, k - maxCnt);
    }

    int integerBreak(int n) {
        double e = exp(1);
        int k = n / e;

        return max(computeProduct(n, k - 1), max(computeProduct(n, k), computeProduct(n, k + 1)));
    }
};
