//
// Created by Emanuel on 16.10.2021.
//

int binarySearchSquareRoot(int n) {
    long long l = 0, r = 46340;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (mid * mid == n)
            return mid;
        if (mid * mid < n) {
            l = mid + 1;
            if (l * l > n)
                return mid;
        }
        else if (mid * mid > n) {
            r = mid - 1;
        }
    }

    return -1;  // this should never happen
}

int mySqrt(int x) {
    return binarySearchSquareRoot(x);
}
