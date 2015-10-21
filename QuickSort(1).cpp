#include<iostream>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<fstream>

template<typename T>
void Swap(T &, T &);

template<typename T>
void quicksort(std::vector<T> & Ve, int Left, int Right) {
    if (Left >= Right)
        return;
    srand(unsigned(time(NULL)));
    int Center = rand()%(Right - Left + 1) + Left;
//std::cout << " Left = " << Left << std::endl;
//std::cout << " Right = " << Right << std::endl;
//std::cout << " Center = " << Center << std::endl;
    T temp = Ve[Center];
    Ve[Center] = Ve[Left];
    // Ve[Left] = temp;  // 此处很重要，防止j越界，即越过Left
    int i = Left + 1, j = Right;
    while (i <= j) {
        while (Ve[i] < temp && i <= Right) i++;
        while (Ve[j] > temp && j >= Left + 1) j--;
        if (i <= j)                  // 有 == 的原因是为了防止当temp等于Ve[i]和
            Swap(Ve[i++], Ve[j--]);  // Ve[j]，而此时刚好 i<j 时会陷入死循环
    }
    if (j >= 0) {
        Ve[Left] = Ve[j];
        Ve[j] = temp;
    }
//std::cout << " i = " << i <<  ", j = " << j << std::endl << std::endl;
    quicksort(Ve, Left, j - 1);
    quicksort(Ve, j + 1, Right);
    return;
}

template<typename T>
void Swap(T & a, T & b) {
    T temp = a;
    a = b;
    b = temp;
    return;
}

int main() {
    std::vector<int> Ve;
    std::ifstream in("Number.txt");
    int n;
    while (in >> n) {Ve.push_back(n);}
    quicksort(Ve, 0, Ve.size() - 1);
    for (unsigned i = 0; i < Ve.size(); i++)
        std::cout << Ve[i] << " ";
    Ve.clear();
    std::cout << std::endl;
    return 0;
}
