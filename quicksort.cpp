#include<iostream>
using namespace std;

void quicksort(int *, int);
void swap(int &, int &);

int main() {
	int N;
	cin >> N;
	int a[N];
	for (int i = 0; i < N; i++)
	    cin >> a[i];
	quicksort(a, N - 1);
	for (int i = 0; i < N; i++)
	    cout << a[i] << " ";
	cout << endl;
	return 0;
}

void quicksort(int * _a, int end) {
	int temp = _a[0];
	int j = 0, i = end;
	while (j < i) {  //
		while (j < i && _a[i] >= temp) {
			i--;
		}
		_a[j] = _a[i];
		while (j < i && _a[j] <= temp) {
			j++;
		}
		_a[i] = _a[j];
	}
	if (0 < end) {
	    _a[i] = temp;
            if (i - 1 >= 0)
	        quicksort(&_a[0], i - 1);
            if (end - i - 1 > 0)
	        quicksort(&_a[i + 1],, end - i - 1);
	}
	return;
}

