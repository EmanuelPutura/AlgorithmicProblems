//
// Created by Emanuel on 19.03.2022.
//

#include <iostream>
using namespace std;

class Solution {
private:
    const int MAX_INT = std::numeric_limits<int>::max();
    const int MIN_INT = std::numeric_limits<int>::min();

public:
    int reverse(int x) {
        int sign = x > 0 ? 1 : -1;
        int result = 0;
        x = abs(x);

        while (x > 0) {
            if (result <= MAX_INT / 10)
                result *= 10;
            else return 0;

            if (MAX_INT - result >= x % 10)
                result += x % 10;
            else if (MAX_INT - result == 7 && x % 10 == 8 && sign == -1 && x / 10 == 0)
                return result * sign - x % 10;
            else return 0;

            x /= 10;
        }

        return result * sign;
    }
};
