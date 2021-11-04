//
// Created by Emanuel on 04.11.2021.
//

#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int lmax = 0, rmax = 0;
        int sum = 0;

        while (l <= r) {
            if (height[l] > lmax)
                lmax = height[l];
            if (height[r] > rmax)
                rmax = height[r];

            int crt;
            if (lmax == rmax || lmax < rmax) {
                crt = std::min(lmax, rmax) - height[l];
                l++;
            }
            else if (lmax > rmax) {
                crt = std::min(lmax, rmax) - height[r];
                r--;
            }

            sum += crt;
        }

        return sum;
    }
};