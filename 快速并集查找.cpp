//���ٲ������ҡ��������е�Ԫ�ر����������ָ����¸�������±� ,�� pt[i] == i ʱ�������ѵ�������������δ������ 

#include<iostream>
using namespace std;

int main() {
	int n, a, b, pt[1000];
	for (int i = 0; i < 1000; i++) pt[i] = i;  //��ʼ��
	//for (int i = 0; i < 10; i++)
		    //cout << pt[i] << " ";
	//cout << endl; 
	cin >> n;  //������ԶԵ�����
	for (int i = 0; i < n; i++) {
		cin >> a >> b;  //�����
		int temp_a = pt[a];//�ҵ��� 
		while (pt[temp_a] != temp_a) {
		    temp_a = pt[temp_a];
		}
		int temp_b = pt[b]; //�ҵ��� 
		while (pt[temp_b] != temp_b) {
			temp_b = pt[temp_b];
		}
		if (temp_a != temp_b) {
			pt[temp_a] = temp_b; // ������ֱ�Ӹ���pt[temp_a] 
			cout << a << " " << b << endl;
		}
		//for (int i = 0; i < 10; i++)
		    //cout << pt[i] << " ";
		//cout << endl;
	}
}

