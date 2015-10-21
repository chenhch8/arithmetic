#include<iostream>
using namespace std;

template<typename T>
void HNT(int, T, T, T);

int main() {
	int n;
	cin >> n;
	HNT(n, 'A', 'C', 'B');
	return 0;
}

template<typename T>
void HNT(int sum, T start, T temp, T goal) {
	if (sum == 0) return;
	HNT(sum - 1, start, goal, temp);
	cout << start << " => " << goal << endl;
	HNT(sum - 1, temp, start, goal);
}
