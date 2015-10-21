#include<iostream>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<fstream>

template<typename T>
void Swap(T &, T &);

template<typename T>
void selection_with_quicksort(std::vector<T> & Ve, int Left, int Right, int k) {
    if (Left >= Right)
        return;
    srand(unsigned(time(NULL)));
    unsigned Center = rand()%(Right - Left + 1) + Left;
    T temp = Ve[Center];
    Ve[Center] = Ve[Left];
    int i = Left + 1, j = Right;
    while (i <= j) {
        while (Ve[i] < temp) i++;
        while (Ve[j] > temp) j--;
        if (i <= j)                  // 有==的原因是为了防止当temp比Ve[i]大且等于
            Swap(Ve[i++], Ve[j--]);  // Ve[j]，而此时刚好i==j时会陷入死循环
    }
    if (j >= 0) {
        Ve[Left] = Ve[j];
        Ve[j] = temp;
    }
    if (j == k) return;
    else if (j > k)
        selection_with_quicksort(Ve, Left, j - 1, k);
    else
        selection_with_quicksort(Ve, j + 1, Right, k);
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
    int n, k;
    std::cout << "k = ";
    std::cin >> k;
    std::ifstream in("Number.txt");
    while (in >> n) {Ve.push_back(n);}
    selection_with_quicksort(Ve, 0, Ve.size() - 1, k - 1);
    std::cout << Ve[k - 1] << std::endl;
    //for (unsigned i = 0; i < Ve.size(); i++)
    //    std::cout << Ve[i] << " ";
    Ve.clear();
    return 0;
}
