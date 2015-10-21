//若 i为素数，则a[i]为1，反之为0； 如果将所有较小的素数的倍数设置为0后a[i]仍为1时则可判断它为素数
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

