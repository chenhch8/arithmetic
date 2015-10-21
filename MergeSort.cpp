#include<iostream>
#include<vector>

template<class T>
void mergesort(std::vector<T> & ve, unsigned Left, unsigned Right) {
    if (Left == Right)
        return;
    unsigned Center = (Left + Right) / 2;

    mergesort(ve, Left, Center);
    mergesort(ve, Center + 1, Right);

    T tempArray[Right - Left + 1];
    int sum = Right - Left + 1;
    unsigned le = Left, ce = Center + 1;

    while (sum--) {
        if (le <= Center && ce <= Right)
            tempArray[sum] = (ve[le] <= ve[ce] ? ve[le++] : ve[ce++]);
        else if (le <= Center)
            tempArray[sum] = ve[le++];
        else
            tempArray[sum] = ve[ce++];
    }

    le = Left;
    for (int i = Right - Left; i >= 0; i--)
        ve[le++] = tempArray[i];
    return;
}

int main() {
    std::vector<int> ve;
    int n;
    while (std::cin >> n)
        ve.push_back(n);
    mergesort(ve, 0, ve.size() - 1);
    for (unsigned i = 0; i < ve.size(); i++)
        std::cout << ve[i] << " ";
    std::cout << std::endl;
    return 0;
}