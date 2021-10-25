//
// Created by Emanuel on 25.10.2021.
//

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i = 0, j = 0;
        int n = firstList.size(), m = secondList.size();
        std::vector<std::vector<int>> intersection;

        while (i < n && j < m) {
            if (firstList[i][1] < secondList[j][0])
                i++;
            else if (secondList[j][1] < firstList[i][0])
                j++;
            else if (firstList[i][0] <= secondList[j][0]) {
                int a = secondList[j][0];
                int b = std::min(firstList[i][1], secondList[j][1]);
                int len = intersection.size();

                if (len && intersection[len - 1][1] == a)
                    intersection[len - 1][1] = b;
                else
                    intersection.push_back(std::vector<int>({a, b}));
                if (firstList[i][1] < secondList[j][1])
                    i++;
                else
                    j++;
            }
            else if (secondList[j][0] <= firstList[i][0]) {
                int a = firstList[i][0];
                int b = std::min(firstList[i][1], secondList[j][1]);
                int len = intersection.size();

                if (len && intersection[len - 1][1] == a)
                    intersection[len - 1][1] = b;
                else
                    intersection.push_back(std::vector<int>({a, b}));
                if (firstList[i][1] < secondList[j][1])
                    i++;
                else
                    j++;
            }
        }

        return intersection;
    }
};