//�롰���ٲ��������㷨���������Ǵ��㷨Ҫ�����������ʱ�������ĸ�һ����Ϊ�¸� ���Դﵽ����·����Ŀ�ģ������ٲ����������޴�Ҫ�󣬹̶�ǰ������������ĸ���Ϊ�¸� �������Ĳ��� 
#include<iostream>
#include<cstdio>
#define n 10000
using namespace std;

int main() {
	int a, b;
	int num[n], size[n];
	for (int i = 0; i < n; i++) {
		num[i] = i; size[i] = 1;
	}
	while (scanf("%d %d", &a, &b) == 2) {
		int temp_a = a, temp_b = b;
		while (num[temp_a] != temp_a) {temp_a = num[temp_a];}
		while (num[temp_b] != temp_b) {temp_b = num[temp_b];}
		if (temp_a == temp_b) continue;
		if (size[temp_a] < size[temp_b]) {
			num[temp_a] = temp_b; size[temp_b] += size[temp_a];
		} else {
			num[temp_b] = temp_a; size[temp_a] += size[temp_b];
		}
		cout << a << " " << b << endl; 
	}
	return 0;
}

