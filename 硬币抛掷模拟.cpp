//pt[i] = j ——i 表示每次实验中出现头像的次数，j 表示经过 m 次实验后出现 i 次头像的实验有 j 次 
#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int heads();

int main() {
	srand((unsigned int)time(0));
	int n, m, cnt,j;
	cin >> n >> m;
	int *pt = new int[n];
	for (int i = 0; i < n; i++)
		*(pt + i) = 0;
	for (int i = 0; i < m; (*(pt + cnt))++, i++) //进行m次实验 
		for (j = 0, cnt = 0; j < n; j++)         //每次实验抛n次 
			if (heads()) cnt++;                  //记录每次实验出现头像的总次数 
	for (int i = 0; i < n; i++) {
		cout << i << "  ";                       //i表示出现头像的次数 
		for (j = 10; j <= *(pt + i); j += 10)    //每出现十次（指实验次数）用一个星号表示 
			cout << "*";
		cout << endl;
	}
	delete []pt;
	return 0;
}

int heads() {
	return rand() < RAND_MAX / 2;
}
