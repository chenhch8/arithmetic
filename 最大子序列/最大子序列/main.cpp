#include"MaxSubSum1.h"
#include<iostream>
#include<cstdlib>

int main() {
    int Sum[20], size = 0, N;
    std::cin >> N;
    while (size < N) {std::cin >> Sum[size++];}
    std::cout << MaxSubSum(Sum, 0, size - 1) << std::endl
        << MaxSubSum2(Sum, size) << std::endl;
    system("pause");
    return 0;
}
