//pt[i] = j ����i ��ʾÿ��ʵ���г���ͷ��Ĵ�����j ��ʾ���� m ��ʵ������ i ��ͷ���ʵ���� j �� 
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
	for (int i = 0; i < m; (*(pt + cnt))++, i++) //����m��ʵ�� 
		for (j = 0, cnt = 0; j < n; j++)         //ÿ��ʵ����n�� 
			if (heads()) cnt++;                  //��¼ÿ��ʵ�����ͷ����ܴ��� 
	for (int i = 0; i < n; i++) {
		cout << i << "  ";                       //i��ʾ����ͷ��Ĵ��� 
		for (j = 10; j <= *(pt + i); j += 10)    //ÿ����ʮ�Σ�ָʵ���������һ���Ǻű�ʾ 
			cout << "*";
		cout << endl;
	}
	delete []pt;
	return 0;
}

int heads() {
	return rand() < RAND_MAX / 2;
}
