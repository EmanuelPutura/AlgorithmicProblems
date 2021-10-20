//
// Created by Emanuel on 20.10.2021.
//

#include <vector>
using namespace std;

class Solution {
public:
    int partner(int index) {
        return index % 2 == 0 ? index + 1 : index - 1;
    }

    int minSwapsCouples(vector<int>& data) {
        int swaps = 0;
        std::vector<int> where_at (data.size());

        for (int i = 0; i < data.size(); ++i)
            where_at[data[i]] = i;

        for (int i = 0; i < data.size(); ++i) {
            for (int j = partner(where_at[partner(data[i])]); j != i; j = partner(where_at[partner(data[i])])) {
                std::swap(data[i], data[j]);
                std::swap(where_at[data[i]], where_at[data[j]]);
                swaps++;
            }
        }

        return swaps;
    }
};
