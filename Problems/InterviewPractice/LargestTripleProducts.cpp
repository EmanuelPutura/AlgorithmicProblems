//
// Created by Emanuel on 07.11.2021.
//

#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here


vector <int> findMaxProduct(vector <int> arr) {
    if (arr.size() < 3)
        return vector<int> (arr.size(), -1);

    vector<int> maxs (4, -1);
    for (int i = 0; i < 3; ++i)
        maxs[i] = arr[i];
    sort(maxs.begin(), maxs.end(), [](int a, int b){return a > b;});

    for (int i = 0; i < 2; ++i)
        arr[i] = -1;
    arr[2] = maxs[0] * maxs[1] * maxs[2];

    for (int i = 3; i < arr.size(); ++i) {
        maxs[3] = arr[i];
        sort(maxs.begin(), maxs.end(), [](int a, int b){return a > b;});
        arr[i] = maxs[0] * maxs[1] * maxs[2];
    }

    return arr;
}