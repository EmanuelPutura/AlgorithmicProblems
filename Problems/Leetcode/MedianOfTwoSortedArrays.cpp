//
// Created by Emanuel on 15.11.2021.
//

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size();
        if (n > m)
            return findMedianSortedArrays(B, A);

        int left = 0, right = n;
        while (left <= right) {
            int i = (left + right) / 2, j = (n + m + 1) / 2 - i;

            if (i > 0 && A[i - 1] > B[j]) {
                right = i - 1;
            }
            else if (i < n && B[j - 1] > A[i]) {
                left = i + 1;
            }
            else {
                int left_max = (i == 0 ? B[j - 1] : A[i - 1]);
                left_max = (i && j ? max(A[i - 1], B[j - 1]) : left_max);

                if ((n + m) % 2 == 1)
                    return left_max;

                int right_min = (i == n ? B[j] : A[i]);
                right_min = (i != n && j != m ? min(A[i], B[j]) : right_min);
                return (left_max + right_min) / 2.0;
            }
        }
        return -1;
    }
};