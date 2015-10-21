#include<cstdio>
#include<iostream>
#define n 10000

using namespace std;

int main() {
    int num[n], size[n], a, b;
    for (int i = 0; i < n; i++) {
	num[i] = i; size[i] = 1;
    }
    while (scanf("%d%d", &a, &b) == 2) {
	int temp_a = a, temp_b = b;
	while (num[temp_a] != temp_a) {      //通过一次处理两个链接，同时将低端链接设置为指向顶端链接所指向的同一个节点，在沿着树上移的过程中，我们可大致对分路径长度 
            num[temp_a] = num[num[temp_a]];  // 可参考图片“路径压缩” 
    	    temp_a = num[temp_a];
	}
	while (num[temp_b] != temp_b) {
	    num[temp_b] = num[num[temp_b]];
	    temp_b = num[temp_b];
	}
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

