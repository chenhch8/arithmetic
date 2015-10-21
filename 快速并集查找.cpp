//快速并集查找——数组中的元素保存的是其所指向的下个数组的下标 ,当 pt[i] == i 时，表明已到根部，否则则未到根部 

#include<iostream>
using namespace std;

int main() {
	int n, a, b, pt[1000];
	for (int i = 0; i < 1000; i++) pt[i] = i;  //初始化
	//for (int i = 0; i < 10; i++)
		    //cout << pt[i] << " ";
	//cout << endl; 
	cin >> n;  //输入测试对的数量
	for (int i = 0; i < n; i++) {
		cin >> a >> b;  //输入对
		int temp_a = pt[a];//找到根 
		while (pt[temp_a] != temp_a) {
		    temp_a = pt[temp_a];
		}
		int temp_b = pt[b]; //找到根 
		while (pt[temp_b] != temp_b) {
			temp_b = pt[temp_b];
		}
		if (temp_a != temp_b) {
			pt[temp_a] = temp_b; // 将根部直接付给pt[temp_a] 
			cout << a << " " << b << endl;
		}
		//for (int i = 0; i < 10; i++)
		    //cout << pt[i] << " ";
		//cout << endl;
	}
}

