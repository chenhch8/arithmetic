#include<iostream>
#include<cstdio>
using namespace std;

int main() {
	int n, p, q;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) a[i] = i;
	while (scanf("%d%d", &p, &q) != EOF) {
		//for (int i = 0; i < n; i++)
		    //cout << a[i] << " ";
		//cout << endl;
		if (a[p] == a[q]) continue;
		for (int t = a[q], i = 0; i < n; i++)
		    if (t == a[i]) a[i] = a[p];
		//for (int i = 0; i < n; i++)
		    //cout << a[i] << " ";
		//cout << endl;
		cout << p << " " << q << endl;
	}
	return 0;
}

