//�� iΪ��������a[i]Ϊ1����֮Ϊ0�� ��������н�С�������ı�������Ϊ0��a[i]��Ϊ1ʱ����ж���Ϊ����
#include<iostream>
#define N 100000

using namespace std;

int main() {
	int a[N];
	for (int i = 2; i < N; i++) a[i] = 1;
	for (int i = 2; i < N; i++)
		if (a[i])
			for (int j = i; j < N / i; j++)
				a[i * j] = 0;
	for(int i = 2; i < N; i++)
		if (a[i]) cout << i << endl;
	return 0;
}

