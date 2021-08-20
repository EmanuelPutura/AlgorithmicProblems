//
// Created by Emanuel on 20.08.2021.
//

#include <iostream>
#include <fstream>
#include <vector>

int read(int& n, std::vector<int>& elems);
void generateArray(int n, int a, int b, int c, std::vector<int>& elems);

void modifiedCountingSort(std::vector<int>& elems, int digit_order);
void radixSort(std::vector<int>& elems, int maxd);

int countDigits(int n);
void print(const std::vector<int>& elems);

int main() {
    int n;
    std::vector<int> elems;

    int maxd = read(n, elems);
    radixSort(elems, maxd);
    print(elems);

    return 0;
}

int read(int& n, std::vector<int>& elems) {
    std::ifstream fin ("radixsort.in");

    int a, b, c;
    fin >> n >> a >> b >> c;
    fin.close();

    generateArray(n, a, b, c, elems);
    fin.close();

    return countDigits(c);
}

void generateArray(int n, int a, int b, int c, std::vector<int>& elems) {
    elems = std::vector<int>(n);
    elems[0] = b;

    for (int i = 1; i < n; ++i)
        elems[i] = (a * elems[i - 1] + b) % c;
}

void modifiedCountingSort(std::vector<int>& elems, int digit_order) {
    std::vector<int> counter(10, 0);
    std::vector<int> result(elems.size());

    auto getDigit = [](int number, int order) {return (number / order) % 10;};

    for (const auto& el : elems)
        counter[getDigit(el, digit_order)]++;

    for (int i = 1; i < 10; ++i)
        counter[i] += counter[i - 1];

    for (int i = elems.size() - 1; i >= 0; --i) {
        auto current_elem = elems[i], current_digit = getDigit(current_elem, digit_order);
        result[counter[current_digit] - 1] = current_elem;
        counter[current_digit]--;
    }

    std::copy(result.begin(), result.end(), elems.begin());
}

void radixSort(std::vector<int>& elems, int maxd) {
    int order = 1;

    for (int d = 1; d <= maxd; ++d) {
        modifiedCountingSort(elems, order);
        order *= 10;
    }
}

int countDigits(int n) {
    int cnt = 0;
    while (n) {
        cnt++;
        n /= 10;
    }
    return cnt;
}

void print(const std::vector<int>& elems) {
    std::ofstream fout("radixsort.out");

    for (int i = 0; i < elems.size(); i += 10)
        fout << elems[i] << ' ';

    fout.close();
}
