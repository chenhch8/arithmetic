#include<iostream>
#include<vector>
#include<fstream>

template<class T>
void shellSort(std::vector<T> & ve) {  // ����һ�������֮�ֳ�����һ�飬�ٿ�ÿ��
    unsigned gap = ve.size() / 2;    // ����������費��Ҫ����˳��ע������
    while (gap >= 1) {                 // ���ͬһ��ve[j]�����ڶ����������ve[j]��������
        for (unsigned i = gap; i < ve.size(); i++) {  // �������࣬�������������ע�ʹ�
            T temp = ve[i];          
            int j;
            for (j = i - gap; j >= 0; j -= gap) {
                if (temp < ve[j])          // ÿ�ζ���temp�Ƚ���Ϊ�˷�ֹͬһ��ve[j]
                    ve[j + gap] = ve[j];   // �����ڶ����������ve[j]��������
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