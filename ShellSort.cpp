#include<iostream>
#include<vector>
#include<fstream>

template<class T>
void shellSort(std::vector<T> & ve) {  // 按照一定间隔将之分成两两一组，再看每组
    unsigned gap = ve.size() / 2;    // 里面的两个需不需要交换顺序。注意分组会
    while (gap >= 1) {                 // 造成同一个ve[j]被分在多组里面造成ve[j]个数增多
        for (unsigned i = gap; i < ve.size(); i++) {  // 个数增多，解决方法在下面注释处
            T temp = ve[i];          
            int j;
            for (j = i - gap; j >= 0; j -= gap) {
                if (temp < ve[j])          // 每次都与temp比较是为了防止同一个ve[j]
                    ve[j + gap] = ve[j];   // 被分在多组里面造成ve[j]个数增多
                else break;
            }
            ve[j + gap] = temp;
        }
        gap /= 2;
    }
}

int main() {
    int n;
    std::vector<int> ve;
    std::ifstream in("Number.txt");
    while (in >> n) {ve.push_back(n);}
    shellSort(ve);
    for (std::vector<int>::iterator it= ve.begin(); it != ve.end(); it++)
        std::cout << *it << " ";
    ve.clear();
    std::cout << std::endl;
    return 0;
}