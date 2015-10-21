#include<iostream>
#include<vector>
#include<fstream>

template<class T>
void InertionSort(std::vector<T> & ve) {
        for (unsigned i = 1; i < ve.size(); i++) {
            T temp = ve[i];          
            int j;
            for (j = i - 1; j >= 0; j--) {
                if (temp < ve[j])
                    ve[j + 1] = ve[j];
                else break;
            }
            ve[j + 1] = temp;
        }
}

int main() {
    std::vector<int> ve;
    std::ifstream in("Number.txt");
    int n;
    while (in >> n) {ve.push_back(n);}
    InertionSort(ve);
    for (std::vector<int>::iterator it= ve.begin(); it != ve.end(); it++)
        std::cout << *it << " ";
    ve.clear();
    std::cout << std::endl;
    return 0;
}