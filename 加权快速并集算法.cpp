//与“快速并集查找算法”的区别是此算法要求在两树相加时，长树的根一定作为新根 ，以达到缩短路径的目的，而快速并集查找则无此要求，固定前树（或后树）的根作为新根 ，其它的不变 
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

